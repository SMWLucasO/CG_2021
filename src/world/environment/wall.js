/**
 * Wall model module, used to generate walls.
 */
World.environment.Wall = (function (three, world) {


    /**
     * Generates a wall, based upon the given input.
     * @param coordinates Object literal {x: a, y: b, z: c}
     * @param sizes Object literal {width: a, height: b, depth: c}
     * @param rotation Number radians of rotation
     * @param material THREE.Material object.
     */
    const generateWall = function(coordinates, sizes, rotation, material) {

        let rightTriangleGeometry = new three.Geometry(1,1,1);

        rightTriangleGeometry.vertices.push(
            new three.Vector3(0,0,0),
            new three.Vector3(.5,0,0),
            new three.Vector3(.5,.5,0),
            new three.Vector3(.5,.5,1),
            new three.Vector3(0,0,1),
            new three.Vector3(.5,0,1),
            // front-of-box (top)
            new three.Vector3(.5,.75,1),
            new three.Vector3(.5,.75,0),
            // back-of-box (top)
            new three.Vector3(.7,.75,1),
            new three.Vector3(.7,.75,0),
            // back-of-box (down)
            new three.Vector3(.7,0,1),
            new three.Vector3(.7,0,0),
        );

        rightTriangleGeometry.faces.push(
            // right 3D triangle part
            new three.Face3(0, 1, 5),
            new three.Face3(5, 0, 4),
            new three.Face3(0, 1, 2),
            new three.Face3(4, 5, 3),
            new three.Face3(0, 4, 3),
            new three.Face3(3, 2, 0),
            new three.Face3(3, 5, 1),
            new three.Face3(3, 2, 1),

            // wall behind
            new three.Face3(1, 11, 9),
            new three.Face3(9, 7, 1),
            new three.Face3(8, 9, 11),
            new three.Face3(11, 10, 8),
            new three.Face3(6, 5, 10),
            new three.Face3(10, 8, 6),
            new three.Face3(6, 7, 1),
            new three.Face3(1, 5, 6),
            new three.Face3(6, 7, 9),
            new three.Face3(9, 8, 6),
            new three.Face3(1, 11, 10),
            new three.Face3(10, 5, 1),
        )

        // Let the sun give color to the wall.
        rightTriangleGeometry.computeFaceNormals();

        let wall = new three.Mesh(rightTriangleGeometry, material);

        // if this is not set, it will look freaky.
        wall.material.side = three.DoubleSide;

        wall.scale.set(sizes.width, sizes.height, sizes.depth);

        wall.position.set(coordinates.x, coordinates.y, coordinates.z);
        wall.rotation.y = rotation;

        return wall;
    }

    return {
        generateWall: generateWall,
    };

})(THREE, World);