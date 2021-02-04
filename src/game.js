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

    /**
     * Add more methods in this class, e.g. to;
     *  - Get models (these models should be in their own classes)
     *  - other stuff, idk really LOL
     */

    return {
        start: start
    };

})(THREE);