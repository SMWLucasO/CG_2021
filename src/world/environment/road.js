/**
 * Road model module, used for generating roads.
 */
World.environment.Road = (function (three, world) {

    let constants = {
        height: 0.1,
        y: 0,
    };

    /**
     * Generate a road.
     * @param coordinates Object literal containing an x/z key:value pair.
     * @param sizes Object literal containing an width/depth key:value pair
     * @param rotation Number the rotation (in radians) of the road
     * @param material THREE.material material which this road uses.
     * @returns {Mesh}
     */
    const generate = function (coordinates, sizes, rotation, material) {

        let roadGeometry = new three.BoxGeometry(sizes.width, constants.height, sizes.depth);

        let road = new three.Mesh(roadGeometry, material);
        road.rotation.y = rotation;

        road.position.set(coordinates.x, constants.y, coordinates.z);

        return road;
    };

    return {
        generate: generate,
    };

})(THREE, World);