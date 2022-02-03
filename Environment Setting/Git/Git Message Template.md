# Mac에서 Git Message Template 만드는 법
1. 우선 txt 파일을 하나 만들어준다.
```javascript
touch ~/.gitmessage.txt
```
2. 그리고 vim 으로 그걸 열어준다.
```javascript
vim ~/.gitmessage.txt
```
3. 커스텀 템플릿 넣고 저장! :wq
4. 마지막으로, commit.template에 이 파일을 설정해준다.
```javascript
git config --global commit.template ~/.gitmessage.txt
```
