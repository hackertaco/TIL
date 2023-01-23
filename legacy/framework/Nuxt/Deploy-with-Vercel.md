## 다른 것 설치할 필요없이
`vercel.json`파일을 루트 디렉토리에 만들고
```javascript
{
  "builds": [
    {
      "src": "nuxt.config.js",
      "use": "@nuxtjs/vercel-builder",
      "config": {}
    }
  ]
}


```
해당 코드를 추가해주면 된다. 
