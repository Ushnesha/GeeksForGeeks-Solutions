## Greedy
### Table of contents
1. [Gas Station](#gasStation)

### Gas Station <a name="gasStation"></a>
##### There are N gas stations along a circular route, where the amount of gas at station i is A[i]. You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.
| Algorithm | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Greedy | Java | O(n) | O(n) |
```java
public class Solution {
    public int canCompleteCircuit(int[] A, int[] B) {
        int tank = 0, idx = 0, tot = 0;
        for(int i = 0; i < A.length; i++){
            int consume = A[i] - B[i];
            tank += consume;
            if(tank<0){
                idx = i+1;
                tank=0;
            }
            tot+=consume;
        }
        return tot<0 ? -1 : idx;
    }
}
```
---
