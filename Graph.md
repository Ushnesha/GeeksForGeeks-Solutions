## Graph
### Table of contents
1. [BFS of a Graph](#bfs)
2. [DFS of a Graph](#dfs) 
3. [Shortest path in an unweighted graph](#shortestpath)

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
### DFS of a Graph <a name="dfs"></a>
##### The task is to do Depth First Traversal of the graph starting from 0.
<a href="url"><img src="https://github.com/Ushnesha/GeeksForGeeks-Solutions/blob/master/images/Graph/dfs%20of%20graph.PNG" width="400"></a>
```java
class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        boolean vis[] = new boolean[V];
        vis[0] = true;
        dfs(adj,0,vis,res);
        return res;
    }
    public void dfs(ArrayList<ArrayList<Integer>> adj, int s, boolean[] vis, ArrayList<Integer> res){
        res.add(s);
        for(int i : adj.get(s)){
            if(vis[i] == false){
                vis[i] = true;
                dfs(adj,i,vis,res);
            }
        }
    }
}
```
---
### Shortest path in an unweighted graph <a name="shortestpath"></a>
##### Find the shortest path from 0 to each node.
```java

import java.io.*;
import java.util.*;

public class Graph{
    int V;
    ArrayList<ArrayList<Integer>> adj;
    
    Graph(int v){
        V=v;
        adj = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<Integer>());
        }
    }
    
    void addEdge(int u, int v){
        adj.get(u).add(v);
        adj.get(v).add(u);
    }
}

class GFG {
    
	public static void main (String[] args) {
	    
		Graph g = new Graph(4);
		g.addEdge(0,1);
		g.addEdge(0,2);
		g.addEdge(1,3);
		g.addEdge(1,2);
		g.addEdge(2,3);
		
		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] vis = new boolean[4];
		int[] dst = new int[4];
		Arrays.fill(dst, -1);
		
		q.add(0);
		vis[0] =true;
		dst[0] = 0;
		
		while(!q.isEmpty()){
		    int u = q.poll();
		    for(int v : g.adj.get(u)){
		        if(vis[v]==false){
		            vis[v]=true;
		            dst[v] = dst[u]+1;
		            q.add(v);
		        }
		    }
		}
        
        //print the dst array that contains shortest path from 0 to that vertex
		for(int i = 0; i < 4; i++){
		    System.out.print(dst[i]+", ");
		}
	}
}
```
---
