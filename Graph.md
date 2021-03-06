## Graph
### Table of contents
1. [BFS of a Graph](#bfs)
2. [DFS of a Graph](#dfs) 
3. [Detect cycle in an undirected graph](#detectCycleUndirected)
4. [Detect cycle in a directed graph](#detectCycleDirected)
5. [Dijsktra's Algorithm](#dijsktra)
6. [Find whether path exist](#findPath)
7. [Shortest path in an unweighted graph](#shortestpath)
8. [Steps by Knight](#knight)
9. [Topological Sort(DFS)](#topoSortDFS)
10. [Topological Sort (Kahn's Algorithm)](#topoSortKahn)

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
### Detect cycle in an undirected graph <a name="detectCycleUndirected"></a>
##### Sol: if on dfs we get a node whose adj is already visited which is not its parent, then a cycle is detected 
```java
class Solution {
    // Function to detect cycle in an undirected graph.
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean vis[] = new boolean[V];
        for(int i = 0; i < V; i++){
            if(!vis[i] && dfs(adj,vis,i,-1)){
                return true;
            }
        }
        return false;
    }
     public boolean dfs(ArrayList<ArrayList<Integer>> adj, boolean[] vis, int s, int par){
         vis[s] = true;
         for(int nbr : adj.get(s)){
             if(!vis[nbr]){
                 if(dfs(adj,vis,nbr,s)) return true;
             }
	     // nbr already visited
             else{
	     	// check if its equal to parent or not
                 if(nbr!=par) return true;
             }
         }
         return false;
     }
}
```
---
### Detect cycle in a Directed graph <a name="detectCycleDirected"></a>
##### Sol: if on dfs we get a node whose adj is already visited which is in the recursion stack recSt[], then a cycle is detected 
```java
class Solution {
    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        // code here
        boolean recSt[] = new boolean[V];
        boolean vis[] = new boolean[V];
        for(int i = 0; i < V; i++){
            if(!vis[i] && cycleCheck(adj,vis,recSt,i)) return true;
        }
        return false;
    }
    public boolean cycleCheck(ArrayList<ArrayList<Integer>> adj, boolean vis[], boolean recSt[], int s){
        vis[s] = true;
        recSt[s] = true;
        for(int nbr : adj.get(s)){
            if(!vis[nbr] && cycleCheck(adj,vis,recSt,nbr)) return true;
            else if(recSt[nbr] == true) return true;
        }
        recSt[s] = false;
        return false;
    }
}
```
---
### Implementing Dijsktra's Algorithm <a name="dijsktra"></a>
##### Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
```java
class NodeG implements Comparable<NodeG> {
    int weight;
    int vertex;
    NodeG(int w, int v){
        weight = w;
        vertex = v;
    }
    public int compareTo(NodeG o) {
        return this.weight == o.weight ? this.vertex-o.vertex : this.weight-o.weight;
    }
}

class Solution
{
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S)
    {
        // Write your code here
        boolean[] chosenNodes = new boolean[V];
        NodeG[] e = new NodeG[V];
        TreeSet<NodeG> q = new TreeSet<NodeG>();
        for(int i = 0; i < V; i++){
            e[i]= new NodeG(Integer.MAX_VALUE,i);
        }
        e[S].weight = 0;
        for(int i = 0; i < V; i++){
            q.add(e[i]);
        }
        while(!q.isEmpty()){
            NodeG p = q.pollFirst();
            chosenNodes[p.vertex] = true;
            // System.out.println(p.vertex + " "+ p.weight);
            for(ArrayList<Integer> nbr : adj.get(p.vertex)){
                if(chosenNodes[nbr.get(0)] == false && p.weight+nbr.get(1) < e[nbr.get(0)].weight){
                    q.remove(e[nbr.get(0)]);
                    e[nbr.get(0)].weight = p.weight+nbr.get(1);
                    q.add(e[nbr.get(0)]);
                }
            }
        }
        int[] dst = new int[V];
        for(int i = 0; i < V; i++){
            dst[i] = e[i].weight;
        }
        return dst;
    }
}
```
---
### Find whether path exist <a name="findPath"></a>
##### Check whether there is a path possible from the source to destination. Src=1, dest=2, emptyCell=3, wall=0
```java
class Solution
{
    //Function to find whether a path exists from the source to destination.
    public boolean is_Possible(int[][] grid)
    {
        // Code here
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1) return found(grid,i,j);
            }
        }
        return false;
    }
    public boolean found(int[][] grid, int i, int j){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0) return false;
        // if destination found, return true
	if(grid[i][j] == 2) return true;
	//once visited make the current cell 0, to prevent back traversal
        grid[i][j] = 0;
        return found(grid,i+1,j) || found(grid,i-1,j) || found(grid,i,j+1)
                    || found(grid,i,j-1);
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
	
	//output : 0 1 1 2
}
```
---
### Steps by Knight <a name="knight"></a>
##### Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.
```java
class Pair{
    int x;
    int y;
    Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution
{
    //Function to find out minimum steps Knight needs to reach target position.
    public int minStepToReachTarget(int KnightPos[], int TargetPos[], int N)
    {
        // Code here
        Queue<Pair> q = new LinkedList<Pair>();
        int dst[][] = new int[N][N];
        int vis[][] = new int[N][N];
        int dx[] = {-2,-2,-1,1,2,2,-1,1};
        int dy[] = {-1,1,-2,-2,-1,1,2,2};
        int srcX = KnightPos[0]-1;
        int srcY = KnightPos[1]-1;
        q.add(new Pair(srcX,srcY));
        while(!q.isEmpty()){
            Pair p = q.poll();
            if(p.x==TargetPos[0]-1 && p.y==TargetPos[1]-1) return dst[p.x][p.y];
            for(int i = 0; i < 8; i++){
                if(isValid(p.x+dx[i], p.y+dy[i], N, vis)){
                    int nX = p.x+dx[i];
                    int nY = p.y+dy[i];
                    dst[nX][nY] = dst[p.x][p.y]+1;
                    q.add(new Pair(nX,nY));
                    vis[nX][nY]=1;
                }
            }
        }
        return -1;
    }
    public boolean isValid(int i, int j, int N, int[][] dst){
        if(i<0 || i >= N || j < 0 || j >= N || dst[i][j] == 1) return false;
        return true;
    }
}
```
---
### Topological Sort(DFS) <a name="topoSortDFS"></a>
```java
class Solution
{
    //Function to return list containing vertices in Topological order. 
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // add your code here
        boolean vis[] = new boolean[V];
        Stack<Integer> st = new Stack<Integer>();
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoSortUtil(adj,vis,st,i);
            }
        }
        int res[] = new int[V];
        int i=0;
        while(!st.isEmpty()){
            res[i++]=st.pop();
        }
        return res;
    }
    public static void topoSortUtil(ArrayList<ArrayList<Integer>> adj, boolean vis[], Stack<Integer> st, int s){
        vis[s] = true;
        for(int nbr : adj.get(s)){
            if(!vis[nbr]){
                topoSortUtil(adj,vis,st,nbr);
            }
        }
        st.push(s);
    }
}
```
---
### Topological Sort(Kahn's Algorithm) <a name="topoSortKahn"></a>
```java
class Solution
{
    //Function to return list containing vertices in Topological order. 
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // add your code here
        int res[] = new int[V];
        int k=0;
        int indegree[] = new int[V];
        for(int i = 0; i < V; i++){
            for(int nbr : adj.get(i)){
                indegree[nbr]++;
            }
        }
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int p = q.poll();
            res[k++] = p;
            for(int nbr : adj.get(p)){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.add(nbr);
            }
        }
        return res;
    }
}
```
---

