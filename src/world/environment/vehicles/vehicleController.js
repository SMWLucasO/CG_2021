World.vehicleController = (function(three) {
    const controller = function (vehicle, debug = false) {
        this.vehicle = vehicle;

        const bb = new THREE.Box3().setFromObject( this.vehicle.obj );

        this.size = bb.getSize();
        this.arrows = {};
        this.debug = debug;
    }

    controller.prototype.move = function () {
        const obstacles = World.getScene().getObjectByName('walls').children;
        const carPos = this.vehicle.obj.position;

        const frontDirection = this.vehicle.obj.getWorldDirection();


        const leftDirection = frontDirection.clone().applyAxisAngle(new THREE.Vector3(0, 1, 0), 25 * (Math.PI / 180));
        const rightDirection = frontDirection.clone().applyAxisAngle(new THREE.Vector3(0, 1, 0), -25 * (Math.PI / 180));

        leftDirection.normalize();
        rightDirection.normalize();

        let closest = null;
        let closestDistance = null;
        let closestDirection = frontDirection;
        let i = 0;

        [frontDirection, leftDirection, rightDirection].forEach((direction => {
            const caster = new THREE.Raycaster(carPos, direction, 0, 8);

            if (this.debug) {
                World.getScene().remove(this.arrows[i]);
                this.arrows[i] = new THREE.ArrowHelper( caster.ray.direction, caster.ray.origin, 8, 0xffffff );
                World.getScene().add(this.arrows[i++]);
            }

            const intersects = caster.intersectObjects(obstacles);

            for (let intersect of intersects) {
                const dist = carPos.distanceTo(intersect.point);
                if (closestDistance === null || dist < closestDistance) {
                    closest = intersect.object;
                    closestDistance = intersect.distance;
                    closestDirection = direction;
                }
            }
        }));

        if (closest !== null) {
            const force = 8 / closestDistance - 0.85;

            switch (closestDirection) {
                case frontDirection:
                case leftDirection:
                    this.vehicle.moveRight(force);
                    break;
                case rightDirection:
                    this.vehicle.moveLeft(force);
                    break;
            }

        } else {
            this.vehicle.moveForward();
        }

    }

    return controller;
})(THREE);