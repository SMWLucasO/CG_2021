World.environment.Tribune = (function (three, world) {

    const settings = {
        tribuneBaseMaterial: new three.MeshPhongMaterial(),
        tribuneRowMaterial: three.MeshPhongMaterial // no new here, (dont want to use same material for all rows).
    };

    const generate = function (x, y, z, rotation, width) {
        // rectangle with stair-like form on it
        // sides have two right triangles

        let tribune = new three.Group();

        let tribuneBaseMesh = generateTribuneBase(width);
        tribune.add(tribuneBaseMesh);

        let tribuneRows = generateTribuneRows(width); // array of row meshes.
        tribuneRows.forEach((v,k) => tribune.add(v));

        tribune.position.set(x,y,z);
        tribune.rotation.y = rotation;

        return tribune;
    }

    const generateTribuneBase = function(depth) {
        // generate right triangle.

        let tribuneBaseGeom = geometries.rightAngleGeometry.generate();
        let tribuneBase = new three.Mesh(tribuneBaseGeom, settings.tribuneBaseMaterial);
        tribuneBase.material.side = three.DoubleSide;

        // set tribune base size.
        tribuneBase.scale.set(25,18,depth)

        return tribuneBase;
    }

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