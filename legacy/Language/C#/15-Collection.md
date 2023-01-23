## 컬렉션
배열이 아닌 방법으로 비슷한 것들끼리 모은것
자료 구조의 일부.
다른 언어에서는 컨테이너라고도 부른다.

- 요소의 수를 바꿀 수 있음.
- 유용한 함수를 기본적으로 제공

그렇다면 배열 쓰는 이유는?
컴퓨터는 배열을 쓰기 때문이다.
더 익숙하다.

- 컬렉션은 배열로 표현되기 어려운 자료들
### 종류
색인, 임의의 key값
중간에 넣고 빼는지, 처음부터 끝까지 컬렉션 데이터 순회할지에 따라 종류를 달리한다.

- List
- Dictionary
- Hashset
- Stack
- Queue
- LinkedList

### List
배열과 거의 비슷한데, 배열의 길이를 언제든지 바꿀 수 있다.

> List<int> scores = new List<int>(총 용량);

[T]대신 <T> 사용!

- 어떤 자료형을 담을지를 표현한다.
- 총 용량을 미리 정하고, 그게 넘으면 알아서 늘려줌
    - 용량을 안 적으면 임의의 크기의 배열을 자동으로 생성
> scores.Add(2)
> scores.AddRange({10, 20})

> scores.Contains(element)
> scores.IndexOf(element)
> scores.LastIndexOf(element)


>scores.Insert(int index, T data)
>
> 리스트의 index번째에 data를 넣기

insert는 한칸씩 뒤에 것을 다 밀기 때문에, for문 돌리면서 하나하나 밀어준다.

잘못된 색인 (capacity 넘으면) 컴파일 오류가 뜬다.

> scores.Remove(T data)
> 하나 지우면, 앞으로 땡겨온다.

> 리스트의 요소에 접근하기 - []
> 실제 요소가 있어야 접근 가능하다.

> 리스트에서 배열로 변환하기
> list.ToArray()

> list.Clear() 모든 요소 지우는 함수

배열보다는 리스트를 많이 사용한다. 사용하기 간편!

### Dictionary
- 리스트와 다른 점은, 색인이 임의의 데이터형이라는 것.
- 연속된 메모리에 데이터 저장을 하는 것이 아니라서, 배열이 더 효율적이다
- 다른 언어에서는 딕셔너리 대신 맵이라고 한다.

> Dictionary<Tkey, TValue> {변수명}= new Dictionary<int, string>()

>값 추가: Add(key, value)

이미 들어 있는 키로 새로운 데이터를 추가하게되면?
예외가 나온다.

예방하려면?
- 중복된 키를 확인 후에 추가한다.
  > bool bSuccess1 = students.TryAdd(key, value)

모든 요소 삭제
> students.Clear()

- 딕셔너리 안에 키가 있는지 확인하기
> students.ContainsKey(key)

- 딕셔너리 안에 값이 있는지 확인하기
> students.ContainsKey(value)

- 딕셔너리 안에 요소 삭제
> students.Remove(key)
> 근데 왜, 얘는 key가 없는데 예외를 던지지 않느냐?

- 정답이 있는 것은 아니지만, 논리적으로 상식적으로 그래야겠다.

- 딕셔너리에서 키와 매핑된 값 가져오기
> students.TryGetValue(key, out value)

- 추가/접근법
    - 만약, key가 없으면 예외를 발생시킨다.
    - 추가를 할 때는, 키가 없으면 키와 값을 새로운 원소로 추가해주는 것이다.


- 언제 쓰면 좋을까?
    - 배열처럼 순서대로 저장하기 힘든 경우.
    - 데이터 저장 공간이 크고, 배열 중간에 데이터를 삽입 및 삭제를 자주 해야할 경우.

### Hashset
- 딕셔너리와 상당히 비슷
- 차이점은, 해시셋은 키만 있음!
- 해시셋은 요소 추가할 때
    - > Add를 쓰는데, 키가 이미 있다고 할지라도, 예외가 나오지 않는다.

- 언제 사용할까?
    - 중복 데이터를 제거할 대.


## 컬렉션과 함께 쓸 때 유용한 것들!

### foreach

#### 어떤 컬렉션이든 순회할 수 있는 방법?
-> foreach
- List, Hashset
> foreach (string name in names)
> {
>      Console.WriteLine(name)
>
 >}

- Dictionary
> foreach (KeyValuePair <string, string>  name in names)
> {
>      Console.WriteLine($"{name.Key}, {name.Value}");
>
>}

- foreach의 한계
  - 방문하는 요소의 값을 바꿀 수는 없다.
  - 현재 방문중인 요소의 색인을 알 방법이 없다.
  - 컬렉션이나 배열을 거꾸로 탐색할 수 없음.


### var
딕셔너리 foreach문은 너무 길다..
> foreach (var  name in names)
> {
>      Console.WriteLine($"{name.Key}, {name.Value}");
>
>}

- 묵시적 자료형, 컴파일러가 알아서 자료형 추론해준다.
- 지역 변수에서만 사용가능
- 긴 자료형을 짧게 줄여준다.
- C++ 에서는 auto라고 표현
- 자료형이 뭔지 바로 알 수 있을 때만 쓰는 게 좋다. 
  - foreach문에서 사용하는 것은 거의 언제나 좋다
  - 