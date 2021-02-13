/**
 * Module for generating customly defined geometries.
 */
const geometries = (function (three) {

    /**
     * 3D right angle geometry generator module
     */
    const rightAngleGeometry = (function () {

        /**
         * Generate a 3D right angle
         *
         * NOTE: Needs the material to have the property 'side' set to THREE.DoubleSide. Use a mesh's
         * scale.set(...) to set width/height/depth.
         *
         * @returns {Geometry}
         */
        const generate = function () {
            let rightAngleGeometry = new three.Geometry(1,1,1);

            // setup the vertices for the 3D right angle
            rightAngleGeometry.vertices.push(
                new three.Vector3(0,0,0),
                new three.Vector3(.5,0,0),
                new three.Vector3(.5,.5,0),
                new three.Vector3(.5,.5,1),
                new three.Vector3(0,0,1),
                new three.Vector3(.5,0,1)
            );

            // set the faces for the 3D right angle.
            rightAngleGeometry.faces.push(
                new three.Face3(0, 1, 5),
                new three.Face3(5, 0, 4),
                new three.Face3(0, 1, 2),
                new three.Face3(4, 5, 3),
                new three.Face3(0, 4, 3),
                new three.Face3(3, 2, 0),
                new three.Face3(3, 5, 1),
                new three.Face3(3, 2, 1)
            );

            // Let the sun give color to the geometry
            rightAngleGeometry.computeFaceNormals();

            return rightAngleGeometry;
        }

        return {
            generate: generate
        }

    })();

    return {
        rightAngleGeometry: rightAngleGeometry
    };

})(THREE);