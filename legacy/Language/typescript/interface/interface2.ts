interface Person2 {
    name: string;
    age?:number;// 있어도 되고 없어도 되는 Optional 이라면
}
function hello2(person:Person2): void{
    console.log(`안녕하세요! ${person.name}입니다.`)
}

const p2: Person2 = {
    name: 'Mark',
    age: 39
}

