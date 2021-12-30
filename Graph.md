## Graph
### Table of contents
1. [BFS of a Graph](#bfs) 

---
### BFS of a Graph <a name="bfs"></a>
##### The task is to do Breadth First Traversal of the graph starting from 0.
<a href="url"><img src="https://github.com/Ushnesha/GeeksForGeeks-Solutions/blob/master/images/Graph/bfs%20of%20graph.PNG" width="400"></a>
```java
class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        Queue<Integer> q = new LinkedList<Integer>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        boolean vis[] = new boolean[V];
        q.add(0);
        vis[0] = true;
        while(!q.isEmpty()){
            int r = q.poll();
            res.add(r);
            for(int i : adj.get(r)){
                if(!vis[i]){
                    vis[i]=true;
                    q.add(i);
                }
            }
        }
        return res;
    }
}
```
---
