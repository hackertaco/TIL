https://start.spring.io/
spring project  쉽게 구성해준다. 

스프링에서는 main (application)을 실행하면, Controller 시행
**@GetMapping**(경로)
> public String home(){
return "home";
}

여기서 리턴하는 값이 resources > templates의 html 경로로 잡히게된다. ViewResolver가 템플릿 엔진을 처리하여 반환한다. 
그런데, 만약 controller mapping이 없다면, static 폴더의 파일을 찾아온다.

동적으로 값을 html tag body에 직접 전달하기 위해서, @ResponseBody 어노테이션을 사용할 수도 있다. 

>@ResponseBody 
> 
> public String helloString(@RequestParam("name") String name){
>
> return "hello "+name; 
>}

ViewRosolver 대신 HttpMessageConverter가 Json을 반환한다.

## Architecture
컨트롤러(웹 MVC) -> Service 참조 -> repository 참조

 
