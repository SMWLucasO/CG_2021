const Game = (function (three) {
    const start = function () {
        World.init();

        loop();
    }

    const loop = function () {
        requestAnimationFrame(loop);
        World.getRenderer().render(World.getScene(), World.getCamera());
        Controller.update();
    }

    return {
        start: start
    };

})(THREE);