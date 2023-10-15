## 380
https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

어렵지는 않은데 속도를 빠르게 하기는 실패한 것 같다. 
우선 해시맵을 이용해야 O(1)이라는 결과가 나올 것 같아 해당 자료구조를 이용했다. 
```java
class RandomizedSet {
    Map<Integer, Boolean> map;

    public RandomizedSet() {
        map  = new HashMap<>();
    }
    
    public boolean insert(int val) {
        if(map.get(val) == null){
            map.put(val, true);
            return true;
        }else {
            return false;
        }
    }
    
    public boolean remove(int val) {
        if(map.get(val) == null){
            return false;
        }else {
            map.remove(val);
            return true;
        }
    }
    
    public int getRandom() {
        // first: Make map keys array
        Integer[] arr = map.keySet().toArray(new Integer[map.size()]);
        // second: get array length

        // third: int random = (int)Math.random * length
        int random = (int) (Math.random() * arr.length);
        // fourth: return map.get(array[random])
        
        return arr[random];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */```
 다만 아래와 같이, 조금 더 빠르게 속도를 낼 수 있다.

 ArrayList와 해시맵 모두를 이용해서, 해시맵은 인덱스를 followup하는 데 사용하고 ArrayList는 값들을 집어넣는 용도다. 