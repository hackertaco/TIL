const slider = document.querySelector('.card_mob_container'),
    slides = Array.from(document.querySelectorAll('.card_mob_box'))
btns = Array.from(document.querySelectorAll('.direct_btn'))
// set up our state
let isDragging = false,
    startPos = 0,
    currentTranslate = 0,
    prevTranslate = 0,
    animationID,
    currentIndex = 0

// add our event listeners
slides.forEach((slide, index) => {
    slide.addEventListener('touchstart', touchStart(index))
    slide.addEventListener('touchend', touchEnd)
    slide.addEventListener('touchmove', touchMove)
})

// prevent menu popup on long press
window.oncontextmenu = function (event) {
    event.preventDefault()
    event.stopPropagation()
    return false
}

function getPositionX(event) {
    return event.touches[0].clientX
}

function touchStart(index) {
    return function (event) {
        currentIndex = index
        startPos = getPositionX(event)
        isDragging = true
        animationID = requestAnimationFrame(animation)
    }
}
function touchMove(event) {
    if (isDragging) {
        const currentPosition = getPositionX(event)
        currentTranslate = prevTranslate + currentPosition - startPos
    }
}

function touchEnd() {
    cancelAnimationFrame(animationID)
    isDragging = false
    const movedBy = currentTranslate - prevTranslate

    // if moved enough negative then snap to next slide if there is one
    if (movedBy < -100 && currentIndex < slides.length - 1) {
        btns[currentIndex].classList.remove('now')
        currentIndex += 1
    }

    // if moved enough positive then snap to previous slide if there is one
    if (movedBy > 100 && currentIndex > 0) {
        btns[currentIndex].classList.remove('now')
        currentIndex -= 1
    }

    setPositionByIndex()
}

function animation() {
    setSliderPosition()
    if (isDragging) requestAnimationFrame(animation)
}

function setPositionByIndex() {
    currentTranslate = currentIndex * -(window.innerWidth*0.83)
    prevTranslate = currentTranslate
    setSliderPosition()
    btns[currentIndex].classList.add('now')
}

function setSliderPosition() {
    slider.style.transform = `translateX(${currentTranslate}px)`
}
