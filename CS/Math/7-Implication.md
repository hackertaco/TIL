## 조건 명제
p -> q
어떤 명제 p가 참이면 다른 명제 q도 참이 된다고 주장하는 명제

다른 합성 명제와 분리해서 배우는 이유:
합성 명제는 매우 기계적이고 직관적이다. 
조건 명제는 전제와 결론이라는 단계가 존재한다. 

애매한 부분이 잇다. 전제가 맞으면 결론은 맞는데, 전제가 틀리면 결론은 틀렸나? 

조건 명제를 다시 전제로 하고, 새로운 결론을 가져가는 명제를 또 만들 수 있다.

## 예시
'해가 나면 바다에 놀러간다'는 조건 명제
해가 나면 > 바다에 놀러갔다 T
해가 나면 > 바다에 안 놀러갓다. F
해가 안나면? 어떻게 되는지 잘 모름.

**전제하지 않은 내용은 무조건 참이다. = 무의미한 참**

-> 판단 불가라고 할 수 있지만, 반드시 결론을 내려야하기 떄문

근데 왜, 판단 불가능한 경우까지 맞다고 하는지?
- 조건 명제를 다른 조건 명제의 전제로 사용할 수 있기에, 결론이 무조건 나와야한다.
- 그것이 과학 및 수학, 즉 세계가 발달해온 과정이다.

만약 "식약청의 테스트를 통과한 음식이라면, 먹어도 배탈이 안 난다." 라는 명제가 있다.
그런데 만약 식약청의 테스트를 안 통과한 음식을 먹고 괜찮다. 그렇다고 식약청을 안 믿을 것인가?

**p == T && q == F일 때만 조건 명제는 거짓이다.**

## 조건 명제와 인과 관계
전제와 결론 사이의 인과관계는 중요하지 않다.
- 전제와 결론이 모두 참이어도, 인과관계가 성립하지 않을수도 있다.
- 이는 말장난, 통계로 장난칠 때 많이 사용한다.
- 전제와 결론이 거짓임이 증명 안되고, 인과관계까지 성립해야 올바른 과학적 사고방법.

## 조건 명제의 역과 이
### 역
p와 q의 위치를 바꾼 것

### 이
p와 q에 not 적용

역과 이는 같은 이야기를 하고있다. 
진리표가 같은 두 명제는 논리적 동치 관계

## 조건 명제의 대우
역과 이가 합쳐진 명제

### 쌍방 조건 명제
(p -> q) && (q -> p)인 경우
표기법 p <-> q
p와 q가 모두 T거나, 모두 F인 경우에만 참이다.
XNOR 게이트와 같다.



## 추론
## 직접 추론
- 긍정 논법 또는 연역 추론
  - p-> q가 참, 명제 p가 참이면 명제 q도 참
- 가설 삼단논법
  - 연쇄 논법
  - 최종 결과가 또 다른 가설
- 선언 삼단 논법
  - p or q 참 , p는 거짓일 때 q는 참
- 논리 융합 = 용해법
  - p 또는 q가 참이고
  - p가 거짓이거나 r이 참이면
  - q 또는 r이 참이어야 한다.

## 증명 방법
- 모순에 의한 증명
  - 귀류법, 반증법이라고도 한다. 
  - p->q의 반대인 (p->q)'가 참이라는 것을 증명한다고 하자.
  - 전체가 거짓인 명제를 만드려면, p는 참이고 q는 거짓이라고 하고 그것이 참임을 증명하려 노력한다.
  - 그것이 실패하면 원래의 명제가 맞는 것이다.
- 모순에 의한 증명의 예 
  - 달력에서 22일 연속인 날을 고르면 그 중 최소한 4일은 같은 요일이다. 
  - 프로그래밍에서 직접적인 활용도가 크지는 않는다.
- 사례에 의한 증명
  - 모든 가능한 경우를 다 하나하나 확인하는 법
  - 경우의 수가 무제한이면 증명 불가.
  - 프로그래밍에서는 가능한 경우가 종종 있다.
- 존재/반례 증명
  - 한 가지 사례만 찾으면 성립하는 증명
    - 존재 증명: 한 사례만 찾으면 ~가 하나라도 있다는 참
    - 반례 증명 한 사례만 찾으면 ~일은 절대 없다는 거짓

- 조건 명제, 인과 관계, 디버깅
  - 함수가 0을 제대로 처리 안한다 -> 크래시가 난다.
  - 앞의 조건을 고치게되면, 전제가 F가 되고, 그럼 q가 무슨 값이든 언제나 명제는 참이 된다. 
  - 그래서 새로운 가설을 세워야 한다.
    - 함수가 0을 제대로 처리한다 -> 크래시가 난다.
    - 확인해본 결과 여전히 크래시가 있다면 
    - 다른 문제가 있을지도 모른다. 
    - 실은 문제의 원인을 파악해야 했던 일이다. 
