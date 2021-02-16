/**
 * Wall model module, used to generate walls.
 */
World.environment.FinishLine = (function (three, world) {


    /**
     * Generates a finishLine, based upon the given input.
     * @param coordinates Object literal {x: a, y: b, z: c}
     * @param blockSize Number size of block
     * @param width Number amount of blocks vertically
     * @param rotation Number radians of rotation
     * @param material THREE.Material object.
     */
    const generate = function(coordinates, blockSize, width, rotation, material) {
        const shapes = [];
        let x = 0;
        let y = 0;

        for (let i = 0; i < width / 2; i++) {

            const shape = new THREE.Shape();
            shape.moveTo(0,0);
            shape.lineTo(x, y + blockSize);
            shape.lineTo(x, y);
            shape.lineTo(x + blockSize, y);
            shape.lineTo(x + blockSize, y + blockSize);
            shape.lineTo(x, y + blockSize);

            if (i * 2 - 1 !== width) {
                shape.lineTo(x, y + (blockSize * 2));
                shape.lineTo(x - blockSize, y + (blockSize * 2));
                shape.lineTo(x - blockSize, y + blockSize);
                shape.lineTo(x, y + blockSize);
            }

            y += (blockSize * 2);
            shapes.push(shape);
        }

        const geometry = new THREE.ShapeGeometry( shapes );

        const mesh = new THREE.Mesh(geometry, material);

        mesh.position.set(coordinates.x, coordinates.y, coordinates.z);
        mesh.rotateY(90 * (Math.PI / 180));
        mesh.rotateX(-90 * (Math.PI / 180));

        return mesh;
    }

    return {
        generate: generate,
    };

})(THREE, World);