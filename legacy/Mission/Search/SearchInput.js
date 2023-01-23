export default function SearchInput({$target, initialState, onChange}){
    this.$element = document.createElement('form')
    this.$element.className = "SearchInput"
    this.state = initialState

    $target.appendChild(this.$element)

    this.render = () => {
        this.$element.innerHTML = `
            <input class="SearchInput__input" type="text" placeholder="프로그래밍 언어를 입력하세요" value="${this.state}"/>
        `
    }

    this.$element.addEventListener('keyup', (e) => {
        const ignoreKeys = ['Enter', 'ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight']
        if(!ignoreKeys.includes(e.key)){

        onChange(e.target.value)
        }
    })

    this.$element.addEventListener('submit', (e) => {
        e.preventDefault()
    })
    this.render()
}