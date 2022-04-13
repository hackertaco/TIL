let startX = 0;
let stopX = 0;
const container = document.querySelector('.card_mob_main_box');
const slider = document.querySelector('.slider');
const first = document.getElementsByClassName('card_mob_box')[0]
const second = document.getElementsByClassName('card_mob_box')[1]
const third = document.getElementsByClassName('card_mob_box')[2]
const width = first.getBoundingClientRect().width
let idx = 0
let target = ''
function move(){
    const moving = startX - stopX;
    console.log(moving)
    if(moving > 0){
        if(moving > width/4){
            idx !== 2 ? idx+=1 : idx = 2
            if(moving >width){
                console.log(moving)
            }else{
                slider.style.transform = `translateX(-${(width-moving)*idx}px)`
            }

            slider.style.transition = 'ease-in-out 0.5s'

        }else{
            slider.style.transform = `translateX(${moving}px)`
            slider.style.transition = 'ease-in-out 0.5s'
        }
    }else{
        console.log(moving)
        if(moving < width/4){
            console.log(moving)
            idx-=1
            idx !== 0 ? idx-=1 : idx = 0
            slider.style.transform = `translateX(-${(width+moving)*idx}px)`
            slider.style.transition = 'ease-in-out 0.5s'
        }

    }
}
function start(e){
    container.addEventListener('touchend', stop)
    startX = e.target.getBoundingClientRect().x

}
function stop(e){
    stopX = e.target.getBoundingClientRect().x

    move()
    container.removeEventListener('touchend', stop)
}

container.addEventListener('touchstart', start)
