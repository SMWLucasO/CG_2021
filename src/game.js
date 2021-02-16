const Game = (function (three) {
    const data = {
        carController: null,
        lastLightStop: null,
    }

    const start = function () {
        Preloader.init().then(() => {
            World.init();

            data.carController = new World.vehicleController(World.environment.getVehicles()[0], false);

            requestAnimationFrame(loop);
        });
    }

    const loop = function (delta) {
        if (data.lastLightStop === null) {
            data.lastLightStop = delta;
        }

        World.getRenderer().render(World.getScene(), World.getCamera());
        Controller.update();

        const startLight = World.environment.getStopPoints()[0];

        if (delta - data.lastLightStop > 8000 && startLight.getState() === 0) {
            startLight.ready();
        } else if (delta - data.lastLightStop > 10000 && startLight.getState() === 1) {
            startLight.go();
        } else if (delta - data.lastLightStop > 55000 && startLight.getState() === 2) {
            startLight.stop();
            data.lastLightStop = delta;
        }


        data.carController.move();

        requestAnimationFrame(loop);
    }

    return {
        start: start
    };

})(THREE);