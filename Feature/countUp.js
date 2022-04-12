const counts = [424, 372, 200]

const countUp = () => {
    const num1 = document.getElementsByClassName("count-num")[0];
    num1.innerText = 0;
    const up1 = setInterval(() => {
        if(num1.innerText != counts[0]){
            count = Number(num1.innerText)
            count += 1
            num1.innerText = count
        }else{
            clearInterval(up1)
        }
    }, 5)
    const num2 = document.getElementsByClassName("count-num2")[0];
    num2.innerText = 0;
    const up2 = setInterval(() => {
        if(num2.innerText != counts[1]){
            count = Number(num2.innerText)
            count += 1
            num2.innerText = count
        }else{
            clearInterval(up2)
        }
    }, 10)
    const num3 = document.getElementsByClassName("count-num3")[0];
    num3.innerText = 0;
    const up3 = setInterval(() => {
        if(num3.innerText != counts[2]){
            count = Number(num3.innerText)
            count += 1
            num3.innerText = count
        }else{
            clearInterval(up3)
        }
    }, 15)
}
  
