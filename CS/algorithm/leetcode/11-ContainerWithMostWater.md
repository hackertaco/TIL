## 11. Container with most water
https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

42. trapping과 이어지는 문제인 것처럼 보이지만 훨씬 쉽다. 
다만 속도를 빠르게 하려면 조건들을 붙여야한다. 
```java
class Solution {
    public int maxArea(int[] height) {
        int left = 0; 
        int right = height.length - 1;

        int h;
        int width;
        int area = 0;
        // 가로도 넓고 세로도 길어야한다. 
        while(left < right) {
            h = Math.min(height[right], height[left]);
            width = right - left;
            if(area < width * h) area = width * h;
            if(h == height[right]) right--;
            if(h == height[left]) left++;
        }

        return area;
    }
}
```

이 코드가 훨씬 빠르다. 그 이유는 내가 생각했을 때 좀 더 효율적으로 index를 증가시켜서인것같다.
```java
class Solution {
    public int maxArea(int[] height) {
        int startIndex = 0, endIndex = height.length - 1;

        int maxVolume = 0;

        while (startIndex < endIndex) {
            int length = Math.min(height[startIndex], height[endIndex]);
            int width = (endIndex - startIndex);
            int volume = width * length;
            maxVolume = Math.max(volume, maxVolume);

            if(height[startIndex] <= height[endIndex]) {
                while(height[startIndex] <= length && startIndex < endIndex) 
                    startIndex++;
            }
            else {
                while(height[endIndex] <= length && startIndex < endIndex) 
                    endIndex--;
            }
        }

        return maxVolume;
    }
}
```