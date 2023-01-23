# 1. getCurrentInstance
Vue.js2의 this를 대체한다.
참조를 통해 사용 가능

## 내부
여러 속성을 가지고 있는데, 가장 유명한 것은 Proxy이다
글로벌 state를 가지고 있어서, 유용하다.

# 2. toRefs
reactive object를, plain object로 변경 
그리고 obj 내부 속성들은 하나하나 ref 다. 

## 유용성
destructive/spread 연산자를 사용할 때 좋다. (Reactivity를 잃지 않는다.)
