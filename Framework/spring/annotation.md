### @Target
어노테이션이 부착될 수 있는 타입 지정.
클래스나 생성자, 메서드 등

### @Operation
Swagger에 사용

### @ResponseStatus
응답코드와 메세지를 지정하여 리턴 가능

### @RequiredArgsConstructor
생성자 주입하기 번거롭다. 이를 보완하기 위해 롬복을 사용해 간단히 생성자 주입 방식의 코딩한다. 

### @RestController
Controller와 다른 점은, HTTP Response body가 생성되는 방식이다. 
@컨트롤러는 주로 view를 반환한다. 

restcontroller는 controller에 responsebody를 합친 것이다. 

### @CrossOrigin
CORS 정책에 대한 설정

### @Transactional
스프링에서 해당 어노테이션을 통하여 트랜잭션 처리를 할 수 있다. 

### @Builder
빌더패턴으로 개체를 생성할 때 호출

### @Id
기본키 직접 할당. 엔티티의 기본키 필드에 값을 직접 넣어 등록한다. 

### @SpringBootTest
실제 어플리케이션을 자신의 로컬 위에 올려서, 실제 데이터베이스와 커넥션이 있는 상태에서 진행하는 테스트