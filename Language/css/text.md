### text에 border 주는 법

-webkit-text-stroke 값을 준다. 다만 safari나 chrome에서만 작동

혹은, text-shadow를 모든 각도에서 준다.
예를 들면, 
```scss
text-shadow:  -1px -1px 0 #000,
0   -1px 0 #000,
1px -1px 0 #000,
1px  0   0 #000,
1px  1px 0 #000,
0    1px 0 #000,
-1px  1px 0 #000,
-1px  0   0 #000;
```

혹은, svg를 사용하는 것도 한 방법이다.
느낌상 제일 깔끔하다.
```html
<svg viewBox="0 0 450 50">
<text y="50">Scalable Title</text>
</svg>
```
로 html을 구성해주고,

```css
svg{
    font   : bold 70px Century Gothic, Arial;
    width  : 100%;
    height : 200px;
}
text{
fill            : none;
stroke          : black;
stroke-width    : 2px;
stroke-linejoin : round;

}
```
로 css 
