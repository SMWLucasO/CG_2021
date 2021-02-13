const Game = (function (three) {
    const data = {
        carController: null
    }

    const start = function () {
        Preloader.init().then(() => {
            World.init();

            data.carController = new World.vehicleController(World.environment.getVehicles()[0]);

            loop();
        });
    }

    const loop = function () {
        requestAnimationFrame(loop);
        World.getRenderer().render(World.getScene(), World.getCamera());
        Controller.update();

        data.carController.move();
    }

    return {
        start: start
    };

})(THREE);