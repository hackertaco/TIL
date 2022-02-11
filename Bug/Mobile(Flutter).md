## Not Showing Keyboard
I/O > keyboard < connect keyboard 해제

## Non-Nullable Error
플러터 버전이 바뀌면서 생긴 것 같은데,
변수를 선언할 때 값을 할당까지 해주어야 한다. 

## Non-Nullable Error
Preparing Analyzing dependencies Inspecting targets to integrate Using `ARCHS` setting to build architectures of target `Pods-Runner`:(``) 
Fetching external sources -> Fetching podspec for `Flutter` from `Flutter` -> 
Fetching podspec for `geolocator_apple` from `.symlinks/plugins/geolocator_apple/ios` 
Resolving dependencies of `Podfile`

위치 추적을 위한 패키지를 설치했는데, 저런 에러가 뜸
이유는? m1 에서 ffi 를 설치하는데 있어 네이티브 빌드 문제가 있기 때문

https://github.com/flutter/flutter/issues/70796 해당 방법으로 해결함
x86에 ffi를 설치해서 해결
