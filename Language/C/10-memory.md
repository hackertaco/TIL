## 메모리의 종류
프로그램에서는 cpu, 메모리 (크게 stack, heap) 두가지를 사용한다. 
- 힙 메모리가 범용적
- 스택은 프로그램마다 일정 부분을 떼어주게 된다. (정확히는 프로그램의 스레드마다)
- cpu에서도 저장공간이 있다 -> 그는 레지스터! 메모리는 아니다. 

## 레지스터
cpu에서 버스를 통해 메모리에 접근하는데, 당연히 느리다.. 이는 주로 dram
cpu 전용 저장 공간이 필요하다는 판단에 레지스터 등장. dram 보다 빠른 sram을 저장. 

이러한 레지스터 키워드를 c에서도 요청해볼 수는 있다.
> register <자료형> <변수명>;

근데 
1) 변수의 주소를 구할 수 없다
2) 전역변수가 아니라 블록 범위에서만 사용 가능하다. 
그리고 실제로 사용하는 것도 그냥 컴파일러가 결정한다. (잘 무시하곤 한다. 예전에는 많이 사용했지만 이제는 컴파일러가 최적화됨)

## 힙 메모리
스택메모리의 단점은
1) 함수 반환시, 데이터가 날아가고
2) 크기도 마음대로 정하지 못한다는 것이다. 

언제든지 프로그래머가 할당하고 없애고 싶은 마음에 힙 메모리를 사용한다. 
그러나, 실수 가능성. 메모리 누수 위험! 

- 스택에 비하여 할당과 해제 속도가 느리다. 
    - 스택은 오프셋 개념으로 빨리빨리 메모리 접근이 가능한 반면
    - 힙은 어디가 메모리 비었는지 확인을 해야한다. 

## 메모리 할당 및 해제함수
### 할당 -동적 메모리
malloc, calloc

> *void malloc(size_t size);

메모리 주소니까 포인터를 반환, 초기화가 안된 상황, 메모리가 없으면 null 반환

> *void calloc(size_t num, size_t size);

자료형 크기와 수를 지정하여서, 원하는 사이즈와 초기화할 값을 설정해준다.
### 해제 -동적 메모리
free
할당 받은 메모리를 해제
### 재할당 -동적 메모리
realloc
> *void realloc(void* ptr, size_t size);

이미 존재하는 메모리의 크기를 size로 변경
- 크기가 커져야 할 때: 뒤에 공간이 없다면 아예 새 공간을 할당한다. 기존 공간을 내용 복사해서 새 주소 반환. 공간 있어도 기존주소를 반환할수도 있고 아닐수도 이싿. 
- 크기가 작아져도 위와 동일한 방식이다. 

### 기타
memset, memcpy, memcmp

> *void memset(void* dest, int ch, size_t count);
> 
> *void memcpy(void* dest, const *void src, size_t count);
> 
> src의 데이터를 count byte만큼 dest에 복사
char로 초기화된다. count는 dest 범위를 넘어서면 안된다.
> 
> > *void memcmp(const int* lhs, const int* rhs, size_t count);

- count만큼 메모리 비교
- 구조체 2개 비교할 때 유용
  - 구조 가진 구조체 내부는 서로 같은데 외부 구조체는 다르면 문제가 생길 수 있다.

## 동적 메모리 할당시 문제
1. malloc 주소를 가지고 포인터 연산에 사용하면 해제시 문제가 발생하므로 복사해서 사용(즉 포인터 분리 필요)
2. 해제한 메모리 또 해제하려해도 크래시가 날 수 있다.
3. 해제한 메모리 또 사용해도 문제 (memory stomp)

### free() 한 뒤에 변수에 NULL 대입해 초기화하여 문제를 해결한다. 

## free는 얼마나 많은 바이트를 해체해야할지 어떻게 아는가
1) 할당 사이즈보다 조금 더 큰 메모리를 할당해서, 제일 앞에 어떤 데이터 (사이즈에 대한 정보) 채워두고 오프셋 더한 값을 주소로 돌려준다. 
2) 주소 해제 요청시, 오프셋만큼 배고 그 앞주소의 데이터에서 실제 바이트 수 확인 후 해제 (메타데이터같다.)


### realloc의 메모리 누수 문제
만약 realloc 메모리 할당 실패하면, 메모리가 누수가 된다. NULL을 반환하게 되는데, 기존 메모리는 해제가 되지않았다. 그래서 메모리 누수가 된다. 
- 올바르게 재할당 하려면 새로운 변수가 필요하다. (변수 복사)
- 정말 주의해야한다.
  - realloc 은 malloc + memcpy + free와 유사하다. 그래서 차라리 이 방법을 안전히 쓰는 경우가 많다.
  - 어짜피 널 퐁린터 반환하면 답이 없으니 그냥 realloc을 사용해서 크래시를 일부러 내는 경우도 있다.

### 동적 메모리의 소유권 문제
누가 소유하나?> 함수가 되어야한다. (메모리를 생성한) 
호출자가 함수 호출시, 동적할당인지 아닌지 모른다. 

## 다중 포인터
두번에 거쳐 값을 찾는다.
