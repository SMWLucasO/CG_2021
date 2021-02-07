/**
 * environment module, used for placing objects in the world.
 */
World.environment = (function (three, world) {

    // WARNING: when tweaking this data, please do not.
    let constants = {
        roads: [
            // Straight roads
            { coords: { x: 0, z: -5 }, size: { width: 8, depth: 65 }, rotation: 0 },
            { coords: { x: 26.5, z: 40 }, size: { width: 8, depth: 30 }, rotation: Math.PI/2 },
            { coords: { x: 53, z: -5 }, size: { width: 8, depth: 65 }, rotation: 0 },
            { coords: { x: 26.5, z: -50 }, size: { width: 8, depth: 30 }, rotation: Math.PI/2 },
            // END straight roads
            // Corners
            { coords: { x: 6.75, z: -43 }, size: { width: 8, depth: 23 }, rotation: Math.PI*1.76 },
            { coords: { x: 46.25, z: -43 }, size: { width: 8, depth: 23 }, rotation: Math.PI*.24 },
            { coords: { x: 46.25, z: 33 }, size: { width: 8, depth: 23 }, rotation: Math.PI*1.76 },
            { coords: { x: 6.75, z: 33 }, size: { width: 8, depth: 23 }, rotation: Math.PI*.24 },
            // END corners
        ]
    }

    let data = {
        floor: null,
        roads: []
    };

    /**
     * Initiate the world's environment.
     */
    const init = function () {
        // init all objects

        // generate floor
        world.getScene().add(getFloor());

        // generate roads
        for(let road of getRoads())
            world.getScene().add(road);

        // temporary object for testing whether the wall works.
        World.getScene().add(World.environment.Wall.generateWall(
            {
                x: 4.7,
                y: 0,
                z: 24
            },
            {
                width: 1,
                height: 2,
                depth: 58
            },
            Math.PI,
            new three.MeshPhongMaterial({color: 0x777777})
        ));

    };

    /**
     * Get the floor, creates one beforehand if none available.
     * @returns {THREE.Mesh}
     */
    const getFloor = function() {
        if(data.floor == null)
            generateFloor();
        return data.floor;
    }

    /**
     * Get the roads, generates them beforehand if none available.
     * @returns {[]}
     */
    const getRoads = function () {
        // roads not generated yet.
        if (data.roads.length === 0)
            generateRoads();

        return data.roads;
    }

    /**
     * Place roads on the floor, these roads are determined by the constants.roads array.
     */
    const generateRoads = function() {
        for(let i = 0; i < constants.roads.length; i++) {
            let material = new three.MeshPhongMaterial();
            generateRoad(constants.roads[i], material);
        }
    }


    /**
     * Generate a road.
     * @param roadData constants.roads array element
     * @param material THREE.Material material to apply to the road
     */
    const generateRoad = function (roadData, material) {
        data.roads.push(world.environment.Road.generateRoad(
            {
                x: roadData.coords.x,
                z: roadData.coords.z,
            },
            {
                width: roadData.size.width,
                depth: roadData.size.depth
            },
            roadData.rotation,
            material
        ));
    }

    /**
     * Generate the floor.
     */
    const generateFloor = function() {
        let texture = new three.TextureLoader().load("assets/world/environment/grass.jpg");
        texture.wrapS = texture.wrapT = three.MirroredRepeatWrapping;
        texture.repeat.set(1024, 1024)
        let material = new three.MeshPhongMaterial();
        material.map = texture;

        data.floor = world.environment.Floor.generate({
            xStart: -250,
            xEnd: 250,
            yStart: -0.1,
            yEnd: -0.00005,
            zStart: -250,
            zEnd: 250
        }, material);
    }

    return {
        init: init,
        getFloor: getFloor,
    }

})(THREE, World);