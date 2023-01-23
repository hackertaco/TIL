let isVisible = false;
window.addEventListener('scroll', function() {
    if ( checkVisible($('.partner-container')) && !isVisible) {
        alert("엘리먼트 보임 !!");
        isVisible=true;
    }
});
function checkVisible( elm, eval ) {
    eval = eval || "object visible";
    const viewportHeight = $(window).height(), // Viewport Height
        scrolltop = $(window).scrollTop(), // Scroll Top
        y = $(elm).offset().top,
        elementHeight = $(elm).height();

    if (eval == "object visible") return ((y < (viewportHeight + scrolltop)) && (y > (scrolltop - elementHeight)));
    if (eval == "above") return ((y < (viewportHeight + scrolltop)));
}
