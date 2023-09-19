# 1. Merge Sort Array
간단한 문젠데 너무 어렵게 생각했다. 
다른 배열을 원 배열에 합치는 문제다.

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int tail1 = m-1;
        int tail2 = n-1;
        int finalTail = m+n-1;
        
        while(tail1 >= 0 && finalTail >= 0 && tail2 >= 0){
            nums1[finalTail--] = nums1[tail1] > nums2[tail2]? nums1[tail1--]: nums2[tail2--];
        }
        while(tail2 >= 0){
            nums1[finalTail--] = nums2[tail2--];
        }
        
    }
}
```

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int j = 0, i = m; j < n; j++)
            nums1[i++] = nums2[j];        
        Arrays.sort(nums1);
    }
}
```