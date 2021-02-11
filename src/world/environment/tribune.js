World.environment.Tribune = (function (three, world) {

    const settings = {

    };

    const generate = function (x, y, z) {
        // rectangle with stair-like form on it
        // sides have two right triangles

        let tribuneBaseMesh = generateTribuneBase();
        let tribuneRows = generateTribuneRows(); // array of row meshes.



    }

    const generateTribuneBase = function() {
        // generate right triangle.

        let tribuneBaseGeom = geometries.rightAngleGeometry.generate(1,1,1);

    }

    const generateTribuneRows = function () {
        // generate sitting blocks
    }

    return {
        generate: generate
    };

})(THREE, World)