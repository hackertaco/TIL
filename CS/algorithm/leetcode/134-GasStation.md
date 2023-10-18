# 138. Gas Station
https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
timeout error가 뜬 첫번째 시도

```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int gasTotal = 0;
        int costTotal = 0;
        int start;
        int curr;
        int left=0;
        int count = 1;
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i<gas.length; i++){
            gasTotal += gas[i];
            costTotal += cost[i];
            if(gas[i] >= cost[i]){
                queue.add(i);
            }
        }
        if(gasTotal < costTotal ){
                return -1;
        }
        start = queue.peek();
        curr = start;
        // left = gas[curr];
        queue.remove(); 
        while(count != gas.length){
            left += gas[curr];
            if(left  < cost[curr]){
                if(queue.isEmpty()){
                    return -1;
                }else{
                    start = queue.peek();
                    curr = start;
                    count = 1;
                    left = 0;
                    queue.remove(); 
                }
            }else{
                System.out.println(left);
                left -= cost[curr];
                curr = (curr+1) % gas.length;
                count++;
            }
        }
        
return start;

    }
}

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0;
        int idx = 0;
        int maxIdx = 0;
        int max = 0;
        for(int i = 0; i<gas.length; i++){
            gas[i] -= cost[i];
            total += gas[i];
        }
        if(total < 0) return -1;
        for(int i = gas.length-1; i>=0; i--){
            if(gas[i] >= 0){
                if(i != 0 && gas[i-1] >= 0){
                    gas[i-1] += gas[i];
                    idx = i-1;
                }
                if(max < gas[i]){
                    max = gas[i];
                    maxIdx = i;
                }
            }
        }
        if(idx == 0){
            if(maxIdx != idx){
                return maxIdx;
            }
        }
        if(idx== 0 && gas[gas.length-1] >= 0 ){
            return gas.length-1;
        }
        return idx;
    }
}
```
아래와 같이 풀어야한다. 나는 생각의 결은 같은데 자꾸만 코드 짜기는 어렵다는 생각이 든다. 
```java
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        idx = gas.length - 1;
        int max = gas[gas.length - 1] - cost[cost.length - 1];
        int sum = max;

        for(int i = gas.length - 2; i >= 0; i--){
            sum += gas[i] - cost[i];
            if(sum > max) {
                max = sum;
                idx = i;
            }
        }
        if(sum < 0)
            return -1;
        return idx;
    }
}

```