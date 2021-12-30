#### Sort 2D array with comparators
##### a.
```java
Arrays.sort(logs, Comparator.comparingInt(o -> o[0]));
```
##### b.
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
