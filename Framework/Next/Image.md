## 로더
로더는 이미지의 URL을 생성하는 기능이다. 
원격 이미지를 사용하기 위해서는, 로더를 사용해야한다.

내장 로더(내장된 Image Optimization API)를 사용할 수 있다.
CDN 또는 이미지 서버에서 직접 이미지를 제공하려면 내장로더 사용해야한다. 
next.config.ts에서 custom 설정도 가능

```json
images: {
    domains: ['rickandmortyapi.com'],
    loader: 'custom',
    path: '/'
  }
```
