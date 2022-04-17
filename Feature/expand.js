

    const question_items = Array.from(document.querySelectorAll('.question_list_box'))
    const folds = Array.from(document.querySelectorAll('.fold'))
    const expands = Array.from(document.querySelectorAll('.expand'))
    const answers = Array.from(document.querySelectorAll('.answer'))
    for(let i =0; i<question_items.length;i++){
    console.log(i)
    question_items[i].addEventListener("click", toggleExpand)
}
    function checkItem (target){
    console.log(event.target)
        for(let i =0; i<question_items.length;i++){
    if(question_items[i].contains(target)){
    return i
}
}
}
    function toggleExpand(){
    const idx = checkItem(event.target)
    console.log(idx)
    console.log(folds[idx].style.display)
    if(folds[idx].style.display === '' || folds[idx].style.display === 'none' ){
    expands[idx].style.display='none'
    folds[idx].style.display='block'
    answers[idx].style.display='block'
}else{
    folds[idx].style.display='none'
    expands[idx].style.display='block'
    answers[idx].style.display='none'
}
}

