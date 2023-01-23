interface Person3 {
    name: string;
    age?:number;// 있어도 되고 없어도 되는 Optional 이라면
    [index: string]:any;
}
function hello3(person:Person3): void{
    console.log(`안녕하세요! ${person.name}입니다.`)
}

const p31: Person3 = {
    name: 'Mark',
    age: 39
}
const p32: Person3 = {
    name: 'anna',
    sisters: ['susan']
}

const p33: Person3 = {
    name: 'dd',
    father:p31,
    mother:p32
}
hello3(p31)
