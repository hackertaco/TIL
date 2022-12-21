## 함수의 필요성
같은 코드를 반복하는 것을 지양함. 실수 방지
재활용성이 올라간다!

## 함수 정의
>static <반환형> <함수명>(<매개변수 목록>)
> {
> 함수바디
> }

- 함수 시그니쳐 : static, 함수명, 매개변수 목록 -> 
- 반환형(필수) -> 데이터를 반환하지 않으면 컴파일 오류가 난다.
- 함수 바디 (필수)

## 메인 함수 매개변수 톺아보기
> static void Main(string[] args){
> 
> }

args를 터미널에서 실행할 떄 넣어줘야한다.
args의 요소 하나에 여러 단어를 넣고싶을 때는, 큰 따옴표로 감쌀 것! ""

## 함수명은 중요하다
- 함수는 블랙박스 -> 어떤 입력을 넣었을 때, 작동 원리를 몰라도 어떤 출력이 나오는지를 알아야한다.
- 함수명 짓는 것은 중요하다.
- 정확히 어떤 기능을 하는지 알려주는 단어를 사용한다 (동사로, 제일 첫 글자는 대문자로)
- 파스칼 표기법으로 (ex.PrintFullName)
- 매개변수는 명사, 첫글자는 소문자, 낙타표기법

### 선조건과 후조건
- 함수가 무슨 일을 하는지에 대한 약속
- 선조건: 함수 실행 시작 전에 참으로 가정한 조건.
- 후조건: 함수 실행 후에 보장되는 조건
> /// 
><param name= "변수">내용</param>
> 문서 주석이라고 부르는 선조건

## 함수의 범위
- 어떤 범위 안에 선언된 것은 범위 밖에서 쓰지 못한다.
- 상위 범위에서 선언한 변수나 상수는 내부에서 쓸 수 있음. 대신 재정의 불가!
- 이름이 같아도 범위가 다르면 다른 변수다 값에 의한 전달!

## 값에 의한 전달, 참조에 의한 전달

### 값에 의한 전달
- 원본 변수와 인자가 다른거다.
- 함수 매개변수에 원본 변수의 사본이 전달
- 원본을 바꾸려면 참조에 의한 전달이 필요하다.
- 매개변수에 ref를 넣어준다. (C# 전용)

## 함수를 작성하는 때
원칙적으로는 함수를 먼저 작성하지말아라! 
언제 작성해야하는지?

- 20줄이 넘는다고 분리를 할 필요는 없다! 
- 코드 중복을 피하고자 할 때, 함수를 작성하는 것이 좋다. 
- 함수가 길어지면 동일한 이름의 지역변수가 생기는 경우가 있는데, 중괄호를 사용하여 범위를 분리한다.
- #region #endregion을 사용해 함수를 접을 수 있게

> #region 이름
> #endregion
