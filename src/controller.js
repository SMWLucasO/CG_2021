const Controller = (function (three) {
    const keys = { // map for keycodes
        forward: 87,
        backward: 83,
        left: 65,
        right: 68,
        up: 81,
        down: 69
    }
    const minHeight = 0; // minimum height the camera should stay at
    const moveSpeed = 1; // movement speed of the camera

    const data = {
        controls: null, // the control object
        keysPressed: { // object to store pressed keys
            [keys.forward]: false,
            [keys.backward]: false,
            [keys.left]: false,
            [keys.right]: false,
            [keys.up]: false,
            [keys.down]: false
        },
        locked: true, // true if overlay is shown
        overlay: null // overlay to prompt the user to click the screen
    };

    const onKeyDown = function(event) {
        // if the overlay is present, do not catch events
        if (data.locked) {
            return;
        }

        if (event.keyCode in data.keysPressed) {
            data.keysPressed[event.keyCode] = true;
        }
    }

    const onKeyUp = function(event) {
        // if the overlay is present, do not catch events
        if (data.locked) {
            return;
        }

        if (event.keyCode in data.keysPressed) {
            data.keysPressed[event.keyCode] = false;
        }
    }

    const lock = function () {
        data.overlay.style.display = 'block';
        data.locked = true;
    }

    const unlock = function () {
        data.overlay.style.display = 'none';
        data.locked = false;
    }

    const createOverlay = function () {
        // create the overlay and insert it into the page
        data.overlay = document.createElement('div');

        data.overlay.style.height = '100vh';
        data.overlay.style.width = '100vw';
        data.overlay.style.position = 'absolute';
        data.overlay.style.top = '0';
        data.overlay.style.left = '0';
        data.overlay.style.backgroundColor = 'rgba(148,148,148,0.4)';
        data.overlay.style.color = 'rgba(12,12,12)';
        data.overlay.style.lineHeight = '100vh';
        data.overlay.style.textAlign = 'center';
        data.overlay.innerText = 'Click to play';
        data.overlay.style.cursor = 'pointer';

        data.overlay.addEventListener('click', () => data.controls.lock());

        document.body.appendChild(data.overlay);
    }

    const init = function () {
        data.controls = new THREE.PointerLockControls(World.getCamera(), World.getRenderer().domElement);

        createOverlay();

        data.controls.addEventListener('lock', unlock);
        data.controls.addEventListener('unlock', lock);

        document.addEventListener('keydown', onKeyDown, false);
        document.addEventListener('keyup', onKeyUp, false);
    }

    const getForce = function (negativeForce, positiveForce) {
        let force = 0;

        if (negativeForce)
            force -= moveSpeed;
        if (positiveForce)
            force += moveSpeed;

        return force / 60;
    }

    const keyPressed = function (key) {
        if (!key in data.keysPressed) {
            return false;
        }

        return data.keysPressed[key];
    }

    const update = function () {
        const vector = new THREE.Vector3(
            getForce(keyPressed(keys.left), keyPressed(keys.right)),
            getForce(keyPressed(keys.down), keyPressed(keys.up)),
            getForce(keyPressed(keys.backward), keyPressed(keys.forward)),
        );

        data.controls.moveForward(vector.z);
        data.controls.moveRight(vector.x);

        let desiredHeight = data.controls.getObject().position.y + vector.y;

        if (desiredHeight > minHeight) {
            data.controls.getObject().position.y = desiredHeight;
        }
    }

    return {
        init: init,
        update: update
    };
})(THREE);