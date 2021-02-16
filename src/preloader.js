const Preloader = (function (three) {
    const data = {
        models: {},
        textures: {},
        overlay: null
    }

    const init = function () {
        showLoadingScreen();


        return new Promise((res, rej) => {
            preLoad().then(() => {
                removeLoadingScreen();
                res();
            });
        });
    };

    /**
     * Show a simple overlay with a loading text
     */
    const showLoadingScreen = function () {
        let overlay = document.createElement('div');
        overlay.style.position = 'absolute';
        overlay.style.top = '0';
        overlay.style.left = '0';
        overlay.style.width = '100vw';
        overlay.style.height = '100vh';
        overlay.style.backgroundColor = 'rgb(148,148,148)';
        overlay.style.color = 'rgb(12,12,12)';
        overlay.style.lineHeight = '100vh';
        overlay.style.textAlign = 'center';
        overlay.innerText = 'Loading...';

        document.body.append(overlay);
        data.overlay = overlay;
    }

    /**
     * remove the loading screen
     */
    const removeLoadingScreen = function () {
        data.overlay.remove();
    }

    /**
     * preload heavy objects that should be available at the start of the game
     */
    const preLoad = function() {
        const load = [
            loadObject('assets/', 'b.obj', 'b.mtl'),
            loadObject('assets/', 'lights.obj', 'lights.mtl'),
            loadTexture("assets/world/environment/grass.jpg"),
            loadTexture("assets/world/environment/road.jpg"),
            loadObject('assets/', 'eltjo.obj', 'eltjo.mtl')
        ];

        return Promise.all(load);
    }

    /**
     * load an Obj file
     */
    const loadObject = function (path, objName, mtlName) {
        return new Promise((res, rej) => {
            const mtlLoader = new THREE.MTLLoader();
            mtlLoader.setPath(path);
            mtlLoader.load(mtlName, (materials) => {
                materials.preload();

                const objLoader = new three.OBJLoader();
                objLoader.setPath(path);
                objLoader.setMaterials(materials);
                objLoader.load( objName, (obj) => {
                    obj.traverse((o) => {
                        if (!o.material) {
                            return;
                        }

                        let materials = o.material;

                        if (!Array.isArray(materials)) {
                            materials = [o.material]
                        }

                        materials.forEach(m => {
                            if ( m.map ) m.map.encoding = THREE.sRGBEncoding;
                            if ( m.emissiveMap ) m.emissiveMap.encoding = THREE.sRGBEncoding;
                        });
                    });

                    data.models[path + objName] = obj;
                    res();
                }, () => null, (e) => rej(e));
            });
        });

    }

    /**
     * Load an texture
     */
    const loadTexture = function (texturePath) {
        new three.TextureLoader().load(texturePath, (texture) => {
            texture.encoding = THREE.sRGBEncoding;
            data.textures[texturePath] = texture;
        });
    }

    const getModel = function (model) {
        return data.models[model].clone();
    };

    const getTexture = function (texture) {
        return data.textures[texture];
    };

    return {
        init: init,
        getModel: getModel,
        getTexture: getTexture,
    };

})(THREE);