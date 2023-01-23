const { calc, css, physics, pointer, transform, value } = window.popmotion;
const { applyOffset, clamp, pipe } = transform;

function getTotalItemsWidth(items) {
    const { left } = items[0].getBoundingClientRect();
    const { right } = items[items.length - 1].getBoundingClientRect();
    return right - left;
}

function angleIsVertical(angle) {
    const isUp = (
        angle <= -90 + 45 &&
        angle >= -90 - 45
    );
    const isDown = (
        angle <= 90 + 45 &&
        angle >= 90 - 45
    );

    return (isUp || isDown);
}

function carousel(container) {
    // Select DOM
    const slider = container.querySelector('.slider');
    const items = slider.querySelectorAll('.item');

    // Calculate slider measurements
    const sliderVisibleWidth = slider.offsetWidth;
    const totalItemsWidth = getTotalItemsWidth(items);

    // Set min/max scroll offsets
    const maxXOffset = 0;
    const minXOffset = - (totalItemsWidth - sliderVisibleWidth);
    const clampXOffset = clamp(minXOffset, maxXOffset);

    // Create slider renderer
    const sliderRenderer = css(slider);
    const sliderX = value(0, (x) => sliderRenderer.set('x', x));

    let action;
    let touchOrigin = { x: 0, y: 0 };

    // Touch event handling
    function stopTouchScroll() {
        document.removeEventListener('touchend', stopTouchScroll);
        if (action) action.stop();
        action = physics({
            from: sliderX.get(),
            velocity: sliderX.getVelocity(),
            friction: 0.2
        }).output(pipe(
            clampXOffset,
            (v) => sliderX.set(v)
        )).start();
    }

    function determineDragDirection(e) {
        const touch = e.changedTouches[0];
        const touchLocation = {
            x: touch.pageX,
            y: touch.pageY
        };
        const distance = calc.distance(touchOrigin, touchLocation);

        if (!distance) return;
        document.removeEventListener('touchmove', determineDragDirection);

        const angle = calc.angle(touchOrigin, touchLocation);
        if (angleIsVertical(angle)) return;

        if (action) action.stop();
        action = pointer(e).start();

        action.output(pipe(
            ({ x }) => x,
            applyOffset(action.x.get(), sliderX.get()),
            clampXOffset,
            (v) => sliderX.set(v)
        ));
    }

    function startTouchScroll(e) {
        document.addEventListener('touchend', stopTouchScroll);
        if (action) action.stop();
        const touch = e.touches[0];
        touchOrigin = {
            x: touch.pageX,
            y: touch.pageY
        };
        document.addEventListener('touchmove', determineDragDirection);
    }

    slider.addEventListener('touchstart', startTouchScroll);
}

carousel(document.querySelector('.container'));
