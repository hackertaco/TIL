Query Optimizer는 각 Operator를 선택해서,
Operator는 iterator interface를 실행한다. 
![img_18.png](img_18.png)

- heap scan 등에 적용 (이 경우 iterator는 없음)
![img_19.png](img_19.png)

- sort -> blocking iterator
![img_20.png](img_20.png)

- 모든 input이 sorted 되었다는 가정 하에 Group by 를 진행
![img_21.png](img_21.png)

이러한 쿼리플랜은 single-threaded + little memory


## Join Iterator
![img_22.png](img_22.png)

### Simple Nested Loops Join
foreach record r in R do
    foreach record s in S do

cost: 

- blocking으로 개선할수도, 다른 페이지를 로드하기 전에 !
  - for each rpage in R: 
    - for each spage in S :
      - for each rtuple
        - for each stuple
- 한번에 두개의 페이지를 로드해도 개선 가능. (block nested loop join)
![img_23.png](img_23.png)
- 그러나 이는 충분한 페이지가 있어야한다. 