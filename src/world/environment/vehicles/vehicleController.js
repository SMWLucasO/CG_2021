World.vehicleController = (function(three) {
    const controller = function (vehicle, debug = false) {
        this.vehicle = vehicle;

        const bb = new THREE.Box3().setFromObject( this.vehicle.obj );

        this.size = bb.getSize();
        this.arrows = {};
        this.debug = debug;
    }

    controller.prototype._debug_draw = function (index, caster, length) {
        World.getScene().remove(this.arrows[index]);
        this.arrows[index] = new THREE.ArrowHelper( caster.ray.direction, caster.ray.origin, length, 0xffffff );
        World.getScene().add(this.arrows[index++]);
    }

    controller.prototype.move = function () {
        const obstacles = World.getScene().getObjectByName('walls').children;
        const carPos = this.vehicle.obj.position;

        const frontDirection = this.vehicle.obj.getWorldDirection();
        const leftDirection = frontDirection.clone().applyAxisAngle(new THREE.Vector3(0, 1, 0), 25 * (Math.PI / 180)).normalize();
        const rightDirection = frontDirection.clone().applyAxisAngle(new THREE.Vector3(0, 1, 0), -25 * (Math.PI / 180)).normalize();
        const LeftTopDirection = frontDirection.clone().setY(25 * (Math.PI / 180)).applyAxisAngle(new THREE.Vector3(0, 1, 0), 25 * (Math.PI / 180)).normalize();

        let closest = null;
        let closestDistance = null;
        let closestDirection = frontDirection;
        let i = 0;
        let shouldStop = false;

        [[frontDirection, 8], [leftDirection, 8], [rightDirection, 8], [LeftTopDirection, 25]].forEach((direction => {
            const caster = new THREE.Raycaster(carPos, direction[0], 0, direction[1]);

            if (this.debug) {
                this._debug_draw(i++, caster, direction[1]);
            }

            for (let stopObject of World.environment.getStopPoints()) {
                if (stopObject.shouldStop()) {
                    const intersects = caster.intersectObjects(stopObject.obj.material ? [stopObject.obj] : stopObject.obj.children);
                    if (intersects.length > 0) {
                        //we are seeing an object that is telling us not to move, like a starting light. Return.
                        shouldStop = true;
                    }
                }
            }

            const wallIntersects = caster.intersectObjects(obstacles);

            for (let intersect of wallIntersects) {
                const dist = carPos.distanceTo(intersect.point);
                if (closestDistance === null || dist < closestDistance) {
                    closest = intersect.object;
                    closestDistance = intersect.distance;
                    closestDirection = direction[0];
                }
            }
        }));

        if (shouldStop)
            return;

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
                default:
                    this.vehicle.moveForward();
            }

        } else {
            this.vehicle.moveForward();
        }

    }

    return controller;
})(THREE);