## LINQ 링큐
데이터를 빠르게 검색, 변환하기 좋은 문법이다.

데이터가 많이 있을 때 처리하고 찾아낸다.

System.Linq 호출
반복문으로 해결하던 많은 걸 한번에 해결!
### OrderBy/ThenBy
OrderBy: 오름차순
ThenBy: 오름차순인데. 별도의 정렬 기준을 추가하는 것

>  var filteredItems = menuItems.OrderBy(m => m.Price).ThenBy(m => m.Name);

내림차순을 하고싶다면?
OrderByDescending

ThenByDescending

#### Where()와 함께 쓸 수 있다. 

처음 것을 return: First()
: 데이터 셋에서 가장 처음 요소를 반환
그런데, 비어있으면 예외가 발생한다.
이 때는 FirstOrDefault()
비어있으면 null 반환

#### All()
모든 것이 그러한지 아닌지 체크. boolean 반환!

#### Any()
하나라도 ! 그러한지 아닌지 체크. boolean 반환

#### ToList() / ToArray() / ToDictionary()

- 현재 쿼리 결과를 리스트, 배열, 딕셔너리로 변환한다.

#### Select
- 데이터셋 가져와서 새로운 데이터셋을 만들어주는 것.

### LINQ 쓸 때 조심!
- 매번 쓸때마다 포문을 돈다는 걸 깨달아야한다. 
  - 더 효율적이게!

- 가독성 주의.
  - 긴 LINQ는 쪼갤 것.


