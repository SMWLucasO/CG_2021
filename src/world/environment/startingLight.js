World.startingLight = (function (three) {
    /**
     * Represents a starting light
     */
    const light = function (x, y, z) {
        this.obj = Preloader.getModel('assets/lights.obj');

        this.obj.scale.set(0.03, 0.03, 0.03);
        this.obj.position.x = x;
        this.obj.position.y = y;
        this.obj.position.z = z;

        const materials = this.obj.getObjectByName('Group_004').material;

        this.colors = {
            green: materials.find(m => m.name === 'Color_G01').color,
            yellow: materials.find(m => m.name === 'Color_E01').color,
            red: materials.find(m => m.name === 'Color_A01').color,
        }

        World.getScene().add(this.obj);

        this.stop();
    }

    /**
     * Make light red
     */
    light.prototype.stop = function () {
        this.colors.red.copy(new THREE.Color(1, 0, 0));
        this.colors.yellow.copy(new THREE.Color(0, 0, 0));
        this.colors.green.copy(new THREE.Color(0, 0, 0));

        this.passable = false;
        this.state = 0;
    }

    /**
     * Make light yellow
     */
    light.prototype.ready = function () {
        this.colors.red.copy(new THREE.Color(0, 0, 0));
        this.colors.yellow.copy(new THREE.Color(1, 1, 0));
        this.colors.green.copy(new THREE.Color(0, 0, 0));
        this.state = 1;
    }

    /**
     * Make light green
     */
    light.prototype.go = function () {
        this.colors.red.copy(new THREE.Color(0, 0, 0));
        this.colors.yellow.copy(new THREE.Color(0, 0, 0));
        this.colors.green.copy(new THREE.Color(0, 1, 0));

        this.passable = true;
        this.state = 2;
    }

    light.prototype.shouldStop = function () {
        return !this.passable;
    }

    light.prototype.getState = function () {
        return this.state;
    }

    return light;
})(THREE);