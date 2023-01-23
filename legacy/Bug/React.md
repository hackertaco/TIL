# 'Switch' is not exported from 'react-router-dom'
-> Switch 말고 Routes 라는 이름으로 변경
-> Route 내부에서도, exact 말고, element로 변경

# React-router-dom 이 뭔가 이상하다? 
-> 버전 6가 좀 이상해. Switch도 안되고, Routes로 바꿔야하는데 안됨
-> connected-router-dom? peer conflict문제가 발생.
-> 결국 버전 5로 다운그레이드함

