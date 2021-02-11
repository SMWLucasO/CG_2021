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
         * @param width {Number} The width of the right angle
         * @param height {Number} The height of the right angle
         * @param depth {Number} The depth of the right angle
         * @returns {Geometry}
         */
        const generate = function (width, height, depth) {
            let rightAngleGeometry = new three.Geometry(width, height, depth);

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

            // set the side of the angle to doubleside, otherwise it will look strange.
            rightAngleGeometry.side = three.DoubleSide;

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