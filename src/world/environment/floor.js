World.environment.Floor = (function (three, world) {

    /**
     * Generate a floor.
     * @param coordinates Object literal of (x, y, z Start/End) e.g. xStart, yEnd, etc.
     * @param material THREE.Material
     * @returns three.Mesh the floor mesh.
     */
    const generate = function(coordinates, material) {

        let width    =    (Math.abs(coordinates.xStart) + Math.abs(coordinates.xEnd)) * 2;
        let height   =    (Math.abs(coordinates.yStart) + Math.abs(coordinates.yEnd)) * 2;
        let depth    =    (Math.abs(coordinates.zStart) + Math.abs(coordinates.zEnd)) * 2;

        let floorGeo = new three.BoxGeometry(width, height, depth);

        let floor = new three.Mesh(floorGeo, (material ?? new three.MeshNormalMaterial()));
        floor.position.set(coordinates.xStart, coordinates.yStart, coordinates.zStart);

        return floor;
    }

    return {
        generate: generate
    };

})(THREE, World);