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

    const getScene = function () {
        if(data.scene == null)
            scene = new THREE.Scene();

        return data.scene;
    };

    const getRenderer = function () {
        if(data.renderer == null)
            data.renderer = new THREE.WebGLRenderer({ // create renderer with default settings delivered by ELO.
                antialias: true,
                alpha: true
            });


        return data.renderer;
    };

    const setRenderer = function (webGLRenderer) {
        data.renderer = webGLRenderer;
    }

    const getCamera = function () {
        if(data.camera == null)
            data.camera = new THREE.PerspectiveCamera(
                75,     // fov - Camera frustum vertical field of view
                window.innerWidth / window.innerHeight, // aspect - Camera frustum aspect ratio
                0.1,   // near - Camera frustum near plane
                1000
            ); // far - Camera frustum far plane
    };

    const getSkybox = function() {
        // get skybox
    }

    const getSun = function () {
        // get the main light source?
    };

    const init = function () {
        getRenderer().setSize(window.innerWidth, window.innerHeight);
        document.body.appendChild(getRenderer().domElement);
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