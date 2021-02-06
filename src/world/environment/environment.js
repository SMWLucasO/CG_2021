World.environment = (function (three, world) {

    let data = {
      floor: null
    };

    const init = function () {
        // init all objects


        let texture = new three.TextureLoader().load("assets/world/environment/grass.jpg");
        texture.wrapS = texture.wrapT = three.MirroredRepeatWrapping;
        texture.repeat.set(1024, 1024)
        let material = new three.MeshPhongMaterial();
        material.map = texture;

        data.floor = World.environment.Floor.generate({
            xStart: -250,
            xEnd: 250,
            yStart: -0.1,
            yEnd: -0.00005,
            zStart: -250,
            zEnd: 250
        }, material);

        World.getScene().add(data.floor);
    };

    const getFloor = function() {
        return data.floor;
    }

    return {
        init: init,
        getFloor: getFloor,
    }

})(THREE, World);