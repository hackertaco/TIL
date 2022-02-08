## const
컴파일 과정에서 절대 변하지 않는 상수를 만들고싶다면
const 제어자 사용. ex (appbar name)
rebuild를 방지해서, 메모리를 아껴주지

## final
변하지는 않지만, 런타임에서 선언되는 상수
값이 변하면 rebuild를 일으킴 (초기화)

두 값 모두 immutable

### _는 뭘까?
제어자. 클래스 내에서 변수 혹은 메소드를 
private하게 만들어줌.
