/**
 * Tribune model module, used to generate tribunes.
 */
World.environment.Tribune = (function (three, world) {

    /**
     * Materials managed by the tribune module, these need to be managed for the model to work.
     */
    const settings = {
        tribuneBaseMaterial: new three.MeshPhongMaterial(),
        tribuneRowMaterial: three.MeshPhongMaterial // no new here, (dont want to use same material for all rows).
    };

    /**
     *
     * @param x {float} the x-coordinate for the tribune
     * @param y {float} the y-coordinate for the tribune
     * @param z {float} the z-coordinate for the tribune
     * @param rotation {float} radian rotation of the object.
     * @param depth {float} the depth of the tribune, in our case the only necessary thing to set.
     * @returns {Group}
     */
    const generate = function (x, y, z, rotation, depth) {
        // rectangle with stair-like form on it
        // sides have two right triangles

        let tribune = new three.Group();

        let tribuneBaseMesh = generateTribuneBase(depth);
        tribune.add(tribuneBaseMesh);

        let tribuneRows = generateTribuneRows(depth); // array of row meshes.
        tribuneRows.forEach((v,k) => tribune.add(v));

        tribune.position.set(x,y,z);
        tribune.rotation.y = rotation;

        return tribune;
    }

    /**
     * Generate base of the tribune
     * @param depth {float} the depth of the tribune base, in our case the only necessary thing to set.
     * @returns {Mesh}
     */
    const generateTribuneBase = function(depth) {
        // generate right triangle.

        let tribuneBaseGeom = geometries.rightAngleGeometry.generate();
        let tribuneBase = new three.Mesh(tribuneBaseGeom, settings.tribuneBaseMaterial);
        tribuneBase.material.side = three.DoubleSide;

        // set tribune base size.
        tribuneBase.scale.set(25,18,depth)

        return tribuneBase;
    }

    /**
     * Generate the rows for the tribune.
     * @param depth {float} the depth of the tribune rows, in our case the only necessary thing to set.
     * @returns {[THREE.Mesh]}
     */
    const generateTribuneRows = function (depth) {
        let tribuneRows = [];

        for(let i = 0; i < 5; i++) {
            let tribuneRowGeom = new three.BoxGeometry(3,4,64)
            let tribuneRow = new three.Mesh(tribuneRowGeom, new settings.tribuneRowMaterial());
            tribuneRow.position.set(i*3,i*2,depth/2);
            tribuneRows.push(
                tribuneRow
            )
        }

        // generate sitting blocks

        return tribuneRows;
    }

    return {
        generate: generate
    };

})(THREE, World)