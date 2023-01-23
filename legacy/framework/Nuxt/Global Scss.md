## 왜 Docs에는 안 나와있는지 모르겠으나

'@nuxtjs/style-resources'를 추가해야한다.
`npm install --save-dev node-sass sass-loader
`에 이어
`npm install --save-dev @nuxtjs/style-resources
`를 추가해주자.

그리고, `nuxt.config.js`에도
`modules: [
'@nuxtjs/style-resources'
],
styleResources: {
scss: ['./assets/scss/*.scss']
},`
추가해주자
