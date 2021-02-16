World.redCar = (function (three) {
    const tire = function (parent, objects, speed = -0.005) {
        this.steering = new THREE.Group();
        this.speed = speed;

        this.meshes = objects.map(objName => parent.getObjectByName(objName));

        const center = new THREE.Vector3();
        this.meshes[0].geometry.computeBoundingBox();
        this.meshes[0].geometry.boundingBox.getCenter(center);

        this.meshes.forEach(obj => {
            obj.geometry.center();
            this.steering.add(obj);
        });

        this.steering.position.copy(center);

        parent.add(this.steering);

        this.maximumTurn = 0.5;
        this.rotated = 0;
        this.lastForce = 1;
    }

    tire.prototype.turnLeft = function (force) {
        if (this.steering.rotation.y < this.maximumTurn) {
            this.steering.rotateY(this.speed * force);
            this.lastForce = force;
        }
    }

    tire.prototype.turnRight = function (force = 1) {
        if (this.steering.rotation.y > this.maximumTurn * -1) {
            this.steering.rotateY(-this.speed * force);
            this.lastForce = force;
        }
    }

    tire.prototype.turnStraight = function () {
        if (this.steering.rotation.y !== 0) {
            this.steering.rotateY(this.steering.rotation.y > 0 ? -this.speed * this.lastForce : this.speed * this.lastForce);
        }
    }

    tire.prototype.moveForward = function (slower = false) {
        this.meshes.forEach(v => {
            v.rotateX(slower ? this.speed * 0.9 : this.speed);
        });
    }

    tire.prototype.moveBackward = function () {
        this.meshes.forEach(v => {
            v.rotateX(-0.1);
        });
    }

    const car = function (initialX = 0, initialY = 0, initialZ = 0, rotate = 0, speed = 0.05) {
        this.maximumTurn = 0.5;
        this.speed = speed;

        const object = Preloader.getModel('assets/b.obj');

        object.position.y = initialY;
        object.position.x = initialX;
        object.position.z = initialZ;

        object.rotateY(rotate);

        World.getScene().add( object );

        this.obj = object;
        window.temp = this;
        this.tires = {
            frontLeft: new tire(object, ["Back_Right_Tire_Plane.063", "Front_Left_Rim_Circle.025", "Front_Left_Brakes_Circle.040"], this.speed),
            frontRight: new tire(object, ["Front_Left_Tire_Plane.009", "Front_Right_Rim_Circle.018", "Front_Right_Brakes_Circle.024"], this.speed),
            backRight: new tire(object, ["Front_Right_Tire_Plane.108", "Back_Right_Rim_Circle.035", "Back_Right_Brakes_Circle.036"], this.speed),
            backLeft: new tire(object, ["Back_Left_Brakes_Plane.060", "Back_Left_Tire_Plane.052", "Back_Left_Rim_Circle.030"], this.speed),
        };

        this.driver = Preloader.getModel('assets/eltjo.obj');
        this.driver.scale.multiplyScalar(0.01);

        this.driver.children.forEach(mesh => {
            mesh.geometry.center();
        });

        this.driver.rotateZ(Math.PI);
        this.driver.rotateY(Math.PI);
        this.driver.scale.set(0.002, 0.002, 0.002);

        World.getScene().add(this.driver);
        this._update_driver();
    }

    car.prototype._update_driver = function () {
        this.driver.position.setFromMatrixPosition(this.obj.matrixWorld);
        this.driver.translateX(-0.4);
        this.driver.translateY(-1);
        this.driver.translateZ(-0.4);
        this.driver.rotation.x = this.obj.rotation.x;
        this.driver.rotation.y = this.obj.rotation.y;
        this.driver.rotation.z = this.obj.rotation.z + Math.PI;
    }

    car.prototype.moveForward = function () {
        this.obj.translateZ(this.speed);
        Object.values(this.tires).forEach(v => {
            v.turnStraight();
            v.moveForward();
        });

        this._update_driver();
    }

    car.prototype.moveRight = function (force = 1) {
        this.obj.rotateY(-(this.speed / 5) * force);
        this.obj.translateZ(this.speed);
        [this.tires.frontLeft, this.tires.frontRight].forEach(v => {
            v.turnRight(force);
            v.moveForward(true);
        });
        [this.tires.backLeft, this.tires.backRight].forEach(v => {
            v.moveForward();
        });

        this._update_driver();
    }

    car.prototype.moveLeft = function (force = 1) {

        this.obj.rotateY((this.speed / 5) * force);
        this.obj.translateZ(this.speed);
        [this.tires.frontLeft, this.tires.frontRight].forEach(v => {
            v.turnLeft(force);
            v.moveForward(true);
        });
        [this.tires.backLeft, this.tires.backRight].forEach(v => {
            v.moveForward();
        });

        this._update_driver();
    }

    car.prototype.moveBack = function () {
        this.obj.translateZ(-this.speed);
        Object.values(this.tires).forEach(v => {
            v.turnStraight();
            v.moveBackward();
        });

        this._update_driver();
    }

    return car;

})(THREE);