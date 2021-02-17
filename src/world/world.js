/**
 * World module, handles all things for the world.
 */
const World = (function (three) {

    // not final.
    let data = {
        scene: null,
        renderer: null,
        camera: null,
        skybox: null,
        sun: null,
        models: [],
    };

    const settings = {
        skybox: { // current skybox: https://reije081.home.xs4all.nl/skyboxes/ (no.3)
            baseUrl: "assets/world/skybox/skyrender",
            directions: ["0001.bmp", "0004.bmp", "0003.bmp", "0006.bmp", "0005.bmp", "0002.bmp"]
        }
    }

    /**
     * Get the scene, will create one if none available.
     * @returns THREE.Scene
     */
    const getScene = function () {
        if(data.scene == null)
            data.scene = new three.Scene();

        return data.scene;
    };

    /**
     * Get the WebGL rendering function, will create one if none available.
     * @returns Three.WebGLRenderer|function
     */
    const getRenderer = function () {
        if(data.renderer == null) {
            data.renderer = new three.WebGLRenderer({ // create renderer with default settings delivered by ELO.
                antialias: true,
                alpha: true
            });

            data.renderer.gammaFactor = 2.2;
            data.renderer.gammaOutput = true;
        }

        return data.renderer;
    };

    /**
     * Set the WebGL rendering function.
     * @param webGLRenderer the WebGL rendering function.
     */
    const setRenderer = function (webGLRenderer) {
        data.renderer = webGLRenderer;
    }

    /**
     * Get the user's camera, will create one if there is none available.
     * @returns THREE.PerspectiveCamera
     */
    const getCamera = function () {
        if(data.camera == null)
            data.camera = new three.PerspectiveCamera(
                75,     // fov - Camera frustum vertical field of view
                window.innerWidth / window.innerHeight, // aspect - Camera frustum aspect ratio
                0.1,   // near - Camera frustum near plane
                5000
            ); // far - Camera frustum far plane

        return data.camera;
    };

    /**
     * Get the skybox, will create one if there is none available.
     * @returns THREE.Mesh
     */
    const getSkybox = function() {
        if(data.skybox == null) {
            let materials = [];

            // load the materials for the skybox (x, -x, y, -y, z, -z) in order
            settings.skybox.directions.forEach(function (v, k) {
                const texture = new three.TextureLoader().load(settings.skybox.baseUrl+v);
                texture.encoding = THREE.sRGBEncoding;

                materials.push(new three.MeshBasicMaterial({
                    map: new three.TextureLoader().load(settings.skybox.baseUrl+v),
                    side: three.BackSide
                }));
            });


            // create cube for the skybox.
            let skyboxGeometry = new THREE.CubeGeometry(5000, 5000, 5000);
            let skyboxMaterial = new THREE.MeshFaceMaterial(materials);

            // generate the skybox itself.
            data.skybox = new THREE.Mesh(skyboxGeometry, skyboxMaterial);
        }
        return data.skybox;
    }

    /**
     * Get the main light source of the world, will create one if there is none available.
     * @returns
     */
    const getSun = function () {
        if(data.sun == null)
            data.sun = new THREE.PointLight(0xFFFFFF, 1, 0, 2); // color, intensity, distance, decay. decay=2=realistic

        return data.sun;
    };

    /**
     * Initiate the World module, this function generates the world.
     */
    const init = function () {
        getRenderer().setSize(window.innerWidth, window.innerHeight);
        document.body.appendChild(getRenderer().domElement);

        getCamera().position.set( 0, 5, 0 );

        // add the skybox and main light source.
        getScene().add(getSkybox());


        // set sun (coordinates related to position of skybox sun
        getSun().position.y = 170;
        getSun().position.z = -200;
        getSun().position.x = 200;
        getScene().add(getSun());

        // initiate all objects on the plane.
        World.environment.init();

        Controller.init();

        //add a bit of ambient light
        const ambientLight = new THREE.AmbientLight( 0x404040, 0.1 ); // soft white light
        World.getScene().add( ambientLight );
    }

    /**
     * Add more methods in this class, e.g. to;
     *  - Get models (these models should be in their own classes)
     *  - other stuff, idk really LOL
     */

    return {
        getScene: getScene,
        getCamera: getCamera,
        getSkybox: getSkybox,
        getRenderer: getRenderer,
        setRenderer: setRenderer,
        getSun: getSun,
        init: init,
    };

})(THREE);