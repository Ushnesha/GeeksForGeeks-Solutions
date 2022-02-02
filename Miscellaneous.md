## Miscellaneous
### Table of contents
1. [Minimum Swap to sort an array](#minSwapSort)

### Minimum Swap to sort an array <a name="minSwapSort"></a>
##### Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Array | Java | O(nLogn) | O(n) |
```java
class Pair<T,S>{
    T f;
    S s;
    Pair(T t1, S t2){
        f = t1;
        s = t2;
    }
    public T getKey(){
        return f;
    }
    public S getValue(){
        return s;
    }
}


class Solution
{
    public int minSwaps(int nums[])
    {
        int V = nums.length;
        //array p of Pair(nums[i] and idx)
        ArrayList<Pair<Integer,Integer>> p = new ArrayList<Pair<Integer,Integer>>();
        for(int i = 0; i < V; i++) p.add(new Pair<Integer,Integer>(nums[i],i));
        //sort p wrt nums[i]
        Collections.sort(p, (a,b) -> a.getKey()-b.getKey());
        int cnt = 0;
        //for every p[i], if p[i]'s idx != the index, then swap p[i] with index and p[i]'s idx
        // decrease i by 1 to get that pointer again
        for(int i = 0; i < V; i++){
            if(p.get(i).getValue() == i) continue;
            else{
                Collections.swap(p, i, p.get(i).getValue());
                cnt++;
                i--;
            }
        }
        return cnt;
    }
}
```
---
