key-value store의 데이터 타입 유연함을 지키면서도, 성능을 높일 수 있는 방법에 대해서 수많은 연구가 있었다.

**그러나**, 이미지나 비디오와 같은 큰 scale의 데이터 파일 저장에 대한 노력은 제한되었다.

따라서, 이 논문에서는 Windows 운영체제와 파일 시스템의 내장 자료구조로 데이터와 index를 분리하는 **WR-Store++를** 제안하였다. **WR-Store++는** key-value store의 효율성을 가져가면서도, file system으로 제한된 저장 공간을 확장해나갈 수도 있다. 더불어, 쉽게 서로 다른 컴퓨팅 환경으로 데이터를 옮길 수도 있다.

이 외에도, chunk 기반 메모리 관리, 병렬 프로세싱으로 GET 작업의 성능을 향상하였다.

**이를 통해,**

1) file system의 공간을 사용하면서 기존 기술인 WR-Store보다 32.74배의 큰 데이터 셋을 저장할 수 있었고,

2) WR-Store와 다른 key-value store들보다 처리 효율이 훨씬 좋았다.

## 기존 연구 정리

- CPU 보틀넥을 일으키는 Log-Structured-Merge tree 기반 스토리지 (ex. LevelDB)
    - 문제 해결을 위해, keys, values를 분리한 후 관리.
    - 압축 빈도를 낮춰 CPU bottleneck을 해결
    - 메모리에 전체 index를 두어 압축 과정 자체를 없애기도하였고
    - GPU가 도입되어, 다양한 workload에 반응하게끔 발전
    - 그 외 해시테이블을 도입하거나, 데이터 도메인에 따라 분리 분석되기도 하였다.
- 효율적으로 key를 검색하는 연구도 진행되었다.
- key-value 스토어 성능을 높이는 연구도 있었다.
- **그러나, 큰 스케일의 값을 다루는 연구는 제한되었다.**
    - Atikoglu 외 몇의 1MB 사이즈 데이터 저장 연구가 있기는 하였지만, 여전히 작았다.
    - 이 연구에서는, value 값은 최대 914.77MB, 총 데이터는 13.59GB의 데이터를 다룬다.

## 연구 배경

### Windows Registry

Windows OS가 사용하는 데이터베이스. 트리구조를 가지고 있으며, registry의 key는 index에서 leaf node가 될 수 있고, root node에서의 경로는 다양한 subkey를 포함하고, 해당 key에 다양한 값을 저장할 수 있다.

registry의 각 value는 다양한 속성을 포함한다. 이 중에서 유일값을 가지는 name이라는 속성이 있다.

### WR-Store

이러한 Windows Registry를 스토리지로 사용하여, key-value 짝을 바로 저장한다. 유일값을 가지는 name 속성에 key를 저장하고, data 속성에 값을 저장하였다. 이는 다양한 크기로 저장될 수 있다.

WR-Store는 Windows Registry의 다양한 key-subkey 관계를 이용하여, 다양한 뎁스의 index를 만들어낼 수 있다.

기존 key-value stores랑 비교했을 때, WR-Store는 비슷하거나 더 좋은 성능을 보였다. 그러나, registry가 작은 사이즈로 메타데이터를 저장하기 위해 만들어진만큼, 데이터 크기에 제한이 있다. (최대 2MB)

그래서, 이 연구에서는 이 한계를 해결한다.

## WR-Store++

### 기본 concept

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8a3f7331-478b-488e-8033-90bdbe87b0a0/Untitled.png)

WR-Store++는 key와 value를 분리한다. 즉, value에는 value값의 위치 포인터만 저장하는 것이다.

실제 값들은 파일 시스템의 개별 파일에 저장된다. 이를 통해, 처리 편의를 위한 인덱스에서의 메타데이터 값을 유지한다.

이를 통해, data storage를 디스크 공간만큼 확장할 수 있다.

### WR-Store++의 작업들

- PUT
    - key-value 짝을 input으로 하여, data storage에는 value, index에는 메타데이터 값을 저장한다.
    - 이미 인덱스에 key값이 있으면, data storage에 값을 업데이트하고, index에 새 entry 값을 삽입한다.
    - 이를 통해 즉각적으로 존재하는 entry를 삭제하지 않고, invalid 마크를 한다.
        - 주기적인 인덱스 압축 과정을 통해 이 entry는 삭제된다.
- GET
    - key를 input으로 하고, value값을 메모리로 복사해온다.
- DELETE
    - key를 input으로 하고 값이 있으면 값을 삭제하고 index에서 entry값을 삭제한다.

### Chunk 기반 스토리지 구조

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9c3cb070-2341-4281-a9c4-2b570922feeb/Untitled.png)

기존 버전은 디스크 I/O가 반복이 되고, 파일 시스템에 랜덤하게 접근하게 되는 문제가 있었다.

따라서, 파일을 큰 스케일의 chunk에 매핑하고, value값을 chunk의 block에 저장하는 chunk 기반 스토리지 구조를 만들었다.

이는 GET 작업시 특히 좋은데, chunk 내의 block으로 file pointer만 옮기면 값을 얻어낼 수 있기 때문이다. 이는 이미 메모리에 위치한 같은 chunk내의 다른 블록에 접근하는 것이라 disk IO를 줄일 수 있다.

### Parallel-Get for WR-Store++

WR-Store++의 Get 작업 성능을 높이기 위해, 각 블록을 같은 크기의 sub-block들로 나누고, 각 sub-block을 스레드에 할당한다. 이는 블록의 병렬 처리를 가능하게 한다.

## 성능 평가

### 실험 환경과 방법

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d634edbe-4767-4e77-854e-0bcd3c009f85/Untitled.png)

- 최대 사이즈는 645MB
- OS의 캐싱으로 성능 변수가 크게 작용되지 않도록, 각각의 DATA ID로 같은 사이즈의 데이터셋을 사용한다.
- 각 DATA ID 당 랜덤한 키로 100번의 PUT, GET, DELETE 작업 시간을 측정한다.
- 그 다음, 상위 하위 각각 7%의 outlier를 제거한 후 평균 처리 시간을 얻어낸다.
- 최종으로 처리량을 계산한다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/edfa736d-2933-4304-aae6-1644b15b883c/Untitled.png)

- 읽기 중심, 쓰기 중심, 평균정도의 작업을 다른 비율로 진행하였다.
- 각 workload에 100번씩 작업하였다.
- Updated의 경우, 우선 DELETE를 하고 PUT하는 작업으로 정의했다.
- 모든 데이터셋을 load 후, 각각의 workload가 진행되었다.
- 이를 진행하는 시간을 측정하였다.

### 실험 결과

`1.WR-Store와의 비교`

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6e2ca64a-27e5-4948-a56b-b95b9f506314/Untitled.png)

- 데이터량이 커지는 DATA ID 6 시점부터 WR-Store의 성능이 떨어지고, WR-Store++의 경우 최소 32.74배의 큰 데이터셋을 관리할 수 있다.
- PUT: 1.96~4.07배. 큰 스케일 값을 저장하는 데 있어서 WR-Store의 오버헤드가 눈에 띈다.
- GET: WR-Store++가 28.09배 빠르다

`2.기존 key-value store과의 비교`

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/94162ad7-d2ed-4d41-8eb4-16e32b1e09d4/Untitled.png)

- 전반적으로 WR-Store++가 뛰어난 성능을 보인다.
- 쓰기 작업에 효율적인 LSM tree에 기반한 LevelDB, RocksDB는 PUT, DELETE 작업이 B+tree 기반 BerkeleyDB보다 훌륭하다.
    - 그러나 DATA ID 8에서 LevelDB는 PUT 작업을 메모리 에러로 하지 못한다. 큰 데이터를 처리하는 데 한계가 있기 때문이다.

`3. mixed workloads에 대한 성능`

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5a4ca0d9-2ecf-475b-80c8-ae0d2d9e0857/Untitled.png)

- WR-Store++가 특히 쓰기 중심의 작업에서 크게 성능을 보인다.

### Chunk 기반 WR-Store++, Parallel-GET WR-Store++ 효과

WR-Store++, Chunk 기반 WR-Store++, Parallel-GET WR-Store++ 세가지를 비교한다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/678a5189-b737-4df9-9085-c33812165514/Untitled.png)

- Parallel-GET WR-Store++은 오히려 데이터크기가 작을 때는 오버헤드 때문에 속도가 느리다.
    - 타겟 블록을 작은 블록으로 나누고 그를 할당하는 작업이 시간이 걸리기 대문이다.
    - 그러나, 데이터 크기가 커질수록 WR-Store++를 크게 능가한다.
- 즉 할당 overhead와 다양한 스레드를 병렬로 처리하는 속도 향상이 성능에 영향을 미친다.

## 추가 논의

- WR-Store++의 안정성: Windows registry는 다른 프로세스에 의해서도 접근되지만, WR-Store++는 새로이 레지스트리에 생성된 경로에만 접근한다. 그래서 conflict가 일어나지 않는다.
- WR-Store++의 이동성: Windows OS가 작동하는 어디든 옮길 수 있고, OS와 관계없이 다른 key-value stores에도 이동할 수 있다.
- WR-Store++의 일관성: 프로세스가 Windows 레지스트리의 항목에 액세스하는 동안 다른 프로세스는 동일한 항목을 수정할 수 있다. 트랜잭션된 API는 레지스트리 항목을 열고 닫으며 항목에 강력한 일관성을 제공한다.

## 혼자 생각해본 결론

### 이 논문의 공헌

- 데이터 크기가 큰 상황에서도 좋은 성능을 유지하는 key-value store 고안
- 데이터 주소를 저장하는 방식으로 운영체제를 참신하게 잘 이용하였다고 생각했다.
- 다양한 기존 key-value store들과 다양한 실험을 통한 성능을 보여주었고, 초기 제안한 모델에서 더 발전시킨 점도 인상적이었다.

### 궁금했던 점

- 왜 Redis와는 비교하지 않았는지 궁금했다.
- Table 3의 workload 산정을 한 이유에 대해서 조금 더 알고 싶었다.
- 성능을 왜 throughput으로만 계산하였는지 이유가 궁금했다.