## 135. -Candy
어려운 문제였다. 일단 그리디로 냅다 푸는 것이 좋다.
양 끝이 중요하고 그걸 기준으로 left , right에서 캔디를 계산하는 방법이 있고, 
그냥 이전 것 대비 작아지거나 커지면 peak 값을 주어서 토탈 값에 더한뒤 작은 peak 값을 빼주는 방법도 있다. 
```java


class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] left = new int[n];
        Arrays.fill(left,1);
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1]+1;      
        }
        int[] right = new int[n];
        Arrays.fill(right,1);
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1]+1;
        }
        int totalCandies = 0;
        for(int i=0; i<n; i++){
            totalCandies += Math.max(left[i],right[i]);
        }
        return totalCandies;
    }
}
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int totalCandies = n;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int currentPeak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                currentPeak++;
                totalCandies += currentPeak;
                i++;
            }

            if (i == n) {
                return totalCandies;
            }

            int currentValley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                currentValley++;
                totalCandies += currentValley;
                i++;
            }

            totalCandies -= Math.min(currentPeak, currentValley);
        }

        return totalCandies;        
    }
}
```