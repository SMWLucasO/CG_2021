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
        ],
        walls: [
            // long wall 1
            { coords: { x: 4.7, y: 0, z: 24.148 }, size: { width: 1, height: 2, depth: 58.4 }, rotation: Math.PI },
            { coords: { x: -4.7, y: 0, z: -37 }, size: { width: 1, height: 2, depth: 64 }, rotation: 0 },

            // long wall 2
            { coords: { x: 48.3, y: 0, z: -34.25 }, size: { width: 1, height: 2, depth: 58.5 }, rotation: 0 },
            { coords: { x: 57.7, y: 0, z: 27.1 }, size: { width: 1, height: 2, depth: 64.2 }, rotation: Math.PI },
            // short wall 1
            { coords: { x: 15.1, y: 0, z: -45.37 }, size: { width: 1, height: 2, depth: 22.8 }, rotation: Math.PI/2 },
            { coords: { x: 41.2, y: 0, z: -54.65 }, size: { width: 1, height: 2, depth: 29.5 }, rotation: Math.PI*1.5 },
            // short wall 2
            { coords: { x: 37.921, y: 0, z: 35.339 }, size: { width: 1, height: 2, depth: 22.8 }, rotation: Math.PI*1.5 },
            { coords: { x: 11.8, y: 0, z: 44.62 }, size: { width: 1, height: 2, depth: 29.5 }, rotation: Math.PI/2 },
            // corner 1
            { coords: { x: 41.7, y: 0, z: 44.4 }, size: { width: 1, height: 2, depth: 23.2 }, rotation: Math.PI*.76 },
            { coords: { x: 48.49, y: 0, z: 23.76 }, size: { width: 1, height: 2, depth: 16.2 }, rotation: Math.PI*1.76 },
            // corner 2
            { coords: { x: 15.625, y: 0, z: 35.55 }, size: { width: 1, height: 2, depth: 16.25 }, rotation: Math.PI*1.24 },
            { coords: { x: -4.57, y: 0, z: 27.4 }, size: { width: 1, height: 2, depth: 23.4 }, rotation: Math.PI*.24 },
            // corner 3
            { coords: { x: 4.51, y: 0, z: -33.78 }, size: { width: 1, height: 2, depth: 16.2 }, rotation: Math.PI*.76 },
            { coords: { x: 11.5, y: 0, z: -54.48 }, size: { width: 1, height: 2, depth: 23.4 }, rotation: Math.PI*1.76 },
            // corner 4
            { coords: { x: 37.4, y: 0, z: -45.6 }, size: { width: 1, height: 2, depth: 16.2 }, rotation: Math.PI*.24 },
            { coords: { x: 57.55, y: 0, z: -37.46 }, size: { width: 1, height: 2, depth: 23.4 }, rotation: Math.PI*-.76 },
        ]
    }

    let data = {
        floor: null,
        roads: [],
        walls: []
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

        // generate the walls.
        for(let wall of getWalls())
            world.getScene().add(wall);

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
     * Get the walls, generates them beforehand if none available.
     * @returns {[]}
     */
    const getWalls = function () {
        if (data.walls.length === 0)
            generateWalls();

        return data.walls;
    }

    /**
     * Prepare roads for insertion, these roads are determined by the constants.roads array.
     */
    const generateRoads = function() {
        for(let i = 0; i < constants.roads.length; i++) {
            let material = new three.MeshPhongMaterial();
            generateRoad(constants.roads[i], material);
        }
    }

    /**
     * Prepare walls for insertion, determined by constants.walls.
     */
    const generateWalls = function() {
        for(let i = 0; i < constants.walls.length; i++) {
            let material = new three.MeshPhongMaterial();
            generateWall(constants.walls[i], material)
        }
    }


    /**
     * Generate a road.
     * @param roadData constants.roads array element
     * @param material THREE.Material material to apply to the road
     */
    const generateRoad = function (roadData, material) {
        // load the texture
        let texture = new three.TextureLoader().load("assets/world/environment/road.jpg");
        // let texture repeat
        texture.wrapS = texture.wrapT = three.MirroredRepeatWrapping;
        // image is 1024x1024
        texture.repeat.set(1024, 1024)
        material.map = texture;

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
     * Generate a wall.
     * @param wallData constants.walls array element
     * @param material THREE.Material to apply to the road.
     */
    const generateWall = function(wallData, material) {
        data.walls.push(world.environment.Wall.generateWall(
            {
                x: wallData.coords.x,
                y: wallData.coords.y,
                z: wallData.coords.z
            },
            {
                width: wallData.size.width,
                height: wallData.size.height,
                depth: wallData.size.depth
            },
            wallData.rotation,
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