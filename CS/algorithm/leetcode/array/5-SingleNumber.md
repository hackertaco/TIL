## 5. Single Number

https://leetcode.com/explore/item/549

배열에서 2개씩 쌍이 있는데, 유일하게 한 숫자만 1개만 있을 때, 이를 찾아내는 문제다.

풀어내는데는 어렵지 않았다. 4번 문제와 조금만 다르게 풀면 되었기 때문이다. 4번은 HashMap으로 풀었으니, 5번은 Hashset으로 풀어보았다.
```java
class Solution {
    public int singleNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<Integer>();
        int j=0;
        for(int i=0; i<nums.length;i++)
        {
            if(!set.add(nums[i])){
                set.remove(nums[i]);
            }else{
                set.add(nums[i]);
            }
        }
       for(int o: set)
           j = o;
    return j;
    }
}
```
![Alt text](image-5.png)
시간보다 공간을 아낀 느낌이다. 

코드의 경우, 아래 for 문은 그냥 int res = set.iterator().next();로 풀어도 된다. 
그런데, 다른 사람들의 코드를 보다가 잊은 것이 생각났다.

더 빠르게 풀려면, 비트 XOR을 그냥 이용하면 되었다. 

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
}
```
어짜피 같은 수는 2개가 한 쌍이므로, 비트패턴을 이용하면 충분히 쉽게 푸는 문제였다.
이걸 까먹다니. 그리고 이걸 이용하다니. 사람들은 참 똑똑하다.