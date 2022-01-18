#### Sort 2D array with comparators
##### a.
```java
class object implements Comparable<object>{
  int x;
  int y;
  object(int a, int b){
    x=a;
    y=b;
  }
  public int compateTo(object ob){
    return this.x-ob.x;
  }
}
public void main(String[] args){
  object obs[];
  Arrays.sort(obs);
}
```
##### b.
```java
Arrays.sort(logs, Comparator.comparingInt(o -> o[0]));
```
##### c.
```java
// for asc
Arrays.sort(logs, (a,b) -> a[0]-b[0])

// for desc
Arrays.sort(logs, (a,b) -> b[0]-a[0])
```

#### Priority Queue of object ob wrt x
##### a.
```java
class object{
  int x,
  int y
}
// for min heap
PriorityQueue<object> pq = new PriorityQueue<object>((a,b) -> a.x - b.x)

// for max heap
PriorityQueue<object> pq = new PriorityQueue<object>((a,b) -> b.x - a.x)
```
#### HashMap computeIfAbsent - if the key is not present then add the key-value to the map otherwise do nothing
```java
HashMap<Integer,ArrayList<Integer>> hm = new HashMap<Integer,ArrayList<Integer>>();
for(int i = 0; i < arr.length; i++){
  hm.computeIfAbsent(i, new ArrayList<Integer>());
  hm.get(i).add(arr[i]);
}
```
