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
        ],
        trees: [{x:42.800906918320514,y:2.1,z:20.77106711426414},{x:41.00372081019628,y:2.1,z:15.413584898913925},{x:45.25089487847577,y:2.1,z:5.633198563079415},{x:43.27827159088951,y:2.1,z:1.040262695762751},{x:45.542652902178524,y:2.1,z:-7.670137312211331},{x:42.966682633476516,y:2.1,z:-13.637908500246954},{x:43.253455108460706,y:2.1,z:-17.794685429151933},{x:45.877601984394246,y:2.1,z:-20.58901855495727},{x:40.87853128791157,y:2.1,z:-20.6850125044092},{x:42.08351877533663,y:2.1,z:-24.499197234485678},{x:46.56496825501704,y:2.1,z:-29.619253351251885},{x:44.59965177369238,y:2.1,z:-32.51497295484805},{x:40.81262737952377,y:2.1,z:-36.02808667344051},{x:39.14946930269656,y:2.1,z:8.058877488068658},{x:44.480126746033875,y:2.1,z:11.773397044724414},{x:39.24693351794818,y:2.1,z:-4.8309488604586175},{x:38.227320606399104,y:2.1,z:-9.54706653461327},{x:36.938538206827054,y:2.1,z:-14.722342462189888},{x:35.28043469877627,y:2.1,z:-19.615630960809863},{x:38.43093058656001,y:2.1,z:-29.897578887899193},{x:33.49888138902255,y:2.1,z:-35.7669499830667},{x:35.671231882019626,y:2.1,z:-40.08341204081022},{x:30.94777987540304,y:2.1,z:-41.72321535799844},{x:26.808783315294693,y:2.1,z:-42.20253006322698},{x:21.31214570631572,y:2.1,z:-42.1001012121797},{x:16.613196067592657,y:2.1,z:-39.983626214700166},{x:12.090672392239126,y:2.1,z:-35.58652150532161},{x:8.828981856571836,y:2.1,z:-30.37249642352637},{x:8.357955115135749,y:2.1,z:-24.22890236187131},{x:14.06483172144245,y:2.1,z:-18.557917413463255},{x:8.462166363933912,y:2.1,z:-13.86760508050905},{x:9.708483335563697,y:2.1,z:-9.664164081940152},{x:8.789407036903082,y:2.1,z:-5.600125466430774},{x:13.54382491007796,y:2.1,z:0.29770460708983715},{x:8.743271301167567,y:2.1,z:4.730438469213999},{x:12.984310349276125,y:2.1,z:10.173296073775186},{x:8.527540054712949,y:2.1,z:15.682013117180832},{x:9.444600325726835,y:2.1,z:19.746481377500928},{x:9.044364002618309,y:2.1,z:24.604378915316925},{x:12.710328697777786,y:2.1,z:26.914811407793337},{x:15.331818083383984,y:2.1,z:32.12591217240459},{x:18.390958780901215,y:2.1,z:28.60524906494244},{x:24.555227936791795,y:2.1,z:31.563710156079},{x:29.024792330672966,y:2.1,z:29.32250643286481},{x:32.44218931994595,y:2.1,z:32.56778695027883},{x:34.138784892631165,y:2.1,z:30.29857095339292},{x:39.819452450126846,y:2.1,z:29.26286643704086},{x:37.99210285802257,y:2.1,z:24.03264293200003},{x:34.47958809329158,y:2.1,z:-26.8948437217338},{x:26.55470878405303,y:2.1,z:-36.03118983387113},{x:22.791064642311667,y:2.1,z:-36.75460776036226},{x:18.633219832339165,y:2.1,z:-33.68829763782093},{x:15.42016330215605,y:2.1,z:-30.07760617392899},{x:13.68980548873888,y:2.1,z:-26.107379842080945},{x:8.127504636243133,y:2.1,z:-19.455428442250152},{x:15.883275103145973,y:2.1,z:-9.967894149237365},{x:14.486813811617589,y:2.1,z:-5.341047102003555},{x:6.501425570237684,y:2.1,z:-0.774926407359725}, {x:8.430413632479276, y:2.1, z:10.19636664404236}],
        tribunes: [
            { coords: { x: -12, y: 0, z: 27 }, rotation: Math.PI, width: 64 },
            { coords: { x: 65, y: 0, z: -37 }, rotation: Math.PI*2, width: 64 },
            { coords: { x: 28, y: 0, z: -62 }, rotation: Math.PI*.5, width: 1 },
            { coords: { x: 28, y: 0, z: 52 }, rotation: Math.PI*1.5, width: 1 },
        ]
    }

    let data = {
        floor: null,
        roads: [],
        walls: [],
        trees: [],
        tribunes: []
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

        // generate the trees
        for (let tree of getTrees())
            world.getScene().add(tree);

        // generate the tribunes
        for (let tribune of getTribunes())
            world.getScene().add(tribune);

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
     * @returns {[THREE.Mesh]}
     */
    const getRoads = function () {
        // roads not generated yet.
        if (data.roads.length === 0)
            generateRoads();

        return data.roads;
    }

    /**
     * Get the walls, generates them beforehand if none available.
     * @returns {[THREE.Mesh]}
     */
    const getWalls = function () {
        if (data.walls.length === 0)
            generateWalls();

        return data.walls;
    }

    /**
     * Get the tribunes, generates them beforehand if none available.
     * @returns {[THREE.Mesh]}
     */
    const getTribunes = function() {
        if (data.tribunes.length === 0)
            generateTribunes();

        return data.tribunes;
    }

    /**
     * get the trees, generates them beforehand if none available.
     * @returns {[THREE.Mesh]}
     */
    const getTrees = function () {
        if(data.trees.length === 0)
            generateTrees();

        return data.trees;
    }

    /**
     * prepare trees for insertion, these trees are determined by the constants.trees array.
     */
    const generateTrees = function () {
        for(let i = 0; i < constants.trees.length; i++) {
            generateTree(constants.trees[i]);
        }
    }

    /**
     * Prepare tribunes for insertion, these tribunes are determined by the constants.tribunes array.
     */
    const generateTribunes = function () {
        for(let i = 0; i < constants.tribunes.length; i++) {
            generateTribune(constants.tribunes[i]);
        }
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
     * Generate a tree, and add it to the trees array.
     * @param treeData {{x: float, y: float, z: float}}
     */
    const generateTree = function (treeData) {
        data.trees.push(
            world.environment.Tree.generate(
                treeData.x,
                treeData.y,
                treeData.z
            )
        );
    }

    /**
     * Generate a tribune, add it to the tribune data array.
     * @param tribuneData {{coords:{x:float,y:float,z:float}, rotation:float}}
     */
    const generateTribune = function (tribuneData) {
        data.tribunes.push(
            world.environment.Tribune.generate(
                tribuneData.coords.x,
                tribuneData.coords.y,
                tribuneData.coords.z,
                tribuneData.rotation,
                tribuneData.width
            )
        );
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

        data.roads.push(world.environment.Road.generate(
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
        data.walls.push(world.environment.Wall.generate(
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