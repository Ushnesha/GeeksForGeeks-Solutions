## Binary Search Tree
### Table of contents
1. [Bottom View of Binary Tree](#bottomview)
2. [Ceil in BST](#ceil)
3. [Check for BST](#bstcheck)
4. [Convert Level Order Traversal to BST](#convertLevelOrder)
5. [Count BST nodes that lie in a given range](#countNodesinRange)
6. [Delete a node from BST](#delete)
7. [Find Common nodes in two BSTs](#findCommon)
8. [Find the closest element in BST](#closestelement)
9. [Floor in BST](#floor)
10. [Insert a node in a BST](#insert)
11. [Lowest Common Ancestor in a BST](#lca)
12. [Minimum element in a BST](#minimumElement)
13. [Pair Sum in BST](#pairsum)
14. [Print BST elements in a given range](#bstInRange)
15. [Search a node in a BST](#search)
16. [Top View of Binary Tree](#topview)
17. [Vertical Traversal of Binary Tree](#verticalTraversal)
---
### Bottom View of Binary Tree <a name="bottomview"></a>
##### If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(n) |
```java
class Solution
{
    static class Pair{
        Node node;
        int hd;
        Pair(Node n, int h){
            node = n;
            hd = h;
        }
    }
    //Function to return a list containing the bottom view of the given tree.
    public ArrayList <Integer> bottomView(Node root)
    {
        // Code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<Pair> q = new LinkedList<Pair>();
        TreeMap<Integer, Integer> mp = new TreeMap<Integer, Integer>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()){
            Pair curr = q.poll();
            Node node = curr.node;
            int hd = curr.hd;
            //override the value inside the treemap since we want the lower elements
            mp.put(hd,node.data);
            if(node.left != null) q.add(new Pair(node.left,hd-1));
            if(node.right != null) q.add(new Pair(node.right, hd+1));
        }
        for(Map.Entry<Integer, Integer> e : mp.entrySet()){
            res.add(e.getValue());
        }
        return res;
    }
}
```
---
### Ceil in BST <a name="ceil"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
//iterative
class Tree 
{
    //Function to return the ceil of given number in BST.
    
    int findCeil(Node root, int key) 
    { 
        if (root == null)
            return -1;
        // Code here
        Node res = null;
        while(root != null){
            if(root.data == key)
                return root.data;
            else if(root.data < key)
                root = root.right;
            else{
                res = root;
                root = root.left;
            }
        }
        return res == null ? -1 : res.data;
    } 
}

//recursive
class Tree 
{
    //Function to return the ceil of given number in BST.
    
    int findCeil(Node root, int key) 
    { 
        if (root == null)
            return -1;
        // Code here
            if(root.data == key)
                return root.data;
            else if(root.data < key)
                return Ceil(root.right, key);
            int res = Ceil(root.left, key);
            return res >= input ? res : root.data;
        }
        
    } 
}
```
---
### Check for BST <a name="bstcheck"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(h) |
```java
public class Solution
{
    //Function to check whether a Binary Tree is BST or not.
    int prev = Integer.MIN_VALUE;
    boolean isBST(Node root)
    {
        // code here.
        if(root == null)
            return true;
        //do inorder traversal and keep the previous node value
        //if prev node value is >= current node (equals to cause bst should not contain duplicate nodes), return false
        if(!isBST(root.left)) return false;
        if(prev >= root.data) return false;
        prev = root.data;
        return isBST(root.right);
    }
}
```
---
### Convert Level Order Traversal to BST <a name="convertLevelOrder"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(n) |
```java
class GFG 
{
    //Function to construct the BST from its given level order traversal.
    public Node constructBST(int[] arr)
    {
        //Write your code here 
        Node root = null;
        for(int i = 0; i < arr.length; i++){
            root = getBST(root, arr[i]);
        }
        return root;
        
    }
    public Node getBST(Node root, int x){
        if(root == null){
            return new Node(x);
        }
        if(root.data > x){
            root.left = getBST(root.left, x);
        }else{
            root.right = getBST(root.right, x);
        }
        
        return root;
    }
}
```
---
### Count BST nodes that lie in a given range <a name="countNodesinRange"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(h) |
```java
class Tree
{
    //Function to count number of nodes in BST that lie in the given range.
    int count = 0;
    int getCount(Node root,int l, int h)
    {
        //Your code here
        getCountUtil(root,l,h);
        return count;
    }
    void getCountUtil(Node root, int l, int h){
        if(root == null) return;
        if(root.data < l)
            getCountUtil(root.right, l, h);
        else if(root.data > h)
            getCountUtil(root.left, l, h);
        
        else{
            count++;
            getCountUtil(root.left, l, root.data);
            getCountUtil(root.right, root.data, h);
        }
            
        
    }
}
```
---
### Delete a node from BST <a name="delete"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class Tree
{
    //Function to delete a node from BST.
	public static Node deleteNode(Node root, int X)
	{
		// code here.
		if(root == null) return null;
		if(root.data > X){
		    root.left = deleteNode(root.left, X);
		}else if(root.data < X){
		    root.right = deleteNode(root.right, X);
		}else{
		    if(root.left == null) return root.right; 
		    else if(root.right == null) return root.left; 
		    else{
		        Node succ = getSucc(root);
		        root.data = succ.data;
		        root.right = deleteNode(root.right, succ.data);
		    }
		}
		return root;
	}
	
	public static Node getSucc(Node root){
	    Node curr = root.right;
	    while(curr!= null && curr.left != null){
	        curr = curr.left;
	    }
	    return curr;
	}
}
```
---
### Find Common nodes in two BSTs <a name="findCommon"></a>
##### Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n1 + n2) | O(h1 + h2) |
```java
class Solution
{
    //Function to find the nodes that are common in both BST.
	public static ArrayList<Integer> findCommon(Node root1,Node root2)
    {
        //code here
        
        Stack<Node> s1 = new Stack<Node>();
        Stack<Node> s2 = new Stack<Node>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        while(true){
            //push the Nodes of left branch of first tree in stack s1 
            while(root1 != null){
                s1.push(root1);
                root1 = root1.left;
            }
            //push the Nodes of left branch of second tree in stack s2 
            while(root2 != null){
                s2.push(root2);
                root2 = root2.left;
            }
            //Both root1 and root2 are null here
            if(!s1.isEmpty() && !s2.isEmpty()){
                root1 = s1.peek();
                root2 = s2.peek();
                if(root1.data == root2.data){
                    res.add(root1.data);
                    s1.pop();
                    s2.pop();
                    // move to the inorder successor 
                    root1 = root1.right;
                    root2 = root2.right;
                }
                else if(root1.data < root2.data){
                    // If Node of first tree is smaller, than that of 
                    // second tree, then its obvious that the inorder 
                    // successors of current Node can have same value 
                    // as that of the second tree Node. Thus, we pop 
                    // from s2 
                    s1.pop();
                    root1 = root1.right;
                    // root2 is set to NULL, because we need 
                    // new Nodes of tree 1 
                    root2 = null;
                }else{
                    s2.pop();
                    root2 = root2.right;
                    root1 = null;
                }
            }
            else break;
        }
        return res;
    }
}
```
---
### Find closest element in BST <a name="closestelement"></a>
##### Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class Solution
{
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    static int minDiff(Node  root, int K) 
    { 
        // Write your code here
        int minDiff = Integer.MAX_VALUE;
        while(root!=null){
            if(root.data == K) return 0;
            else if(root.data > K){
                minDiff = Math.min(minDiff, Math.abs(root.data - K));
                root = root.left;
            }else{
                minDiff = Math.min(minDiff, Math.abs(root.data - K));
                root = root.right;
            }
        }
        return minDiff;
    } 
}
```
---
### Floor in BST <a name="floor"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class Sol
{
    //Function to return the floor of given number in BST.
    
    int floor(Node root, int key) 
    { 
        //code here.
        Node res = null;
        while(root != null){
            //if root val = key, return root
            if(root.data == key) return root.data;
            //if root val > key, then go to the left subtree 
            //since left subtree is smaller than the root
            else if(root.data > key)
                root = root.left;
            //else if root val < key, update the res and go to the right subtree
            //the right subtree has data greater than the root and may find the 
            //greatest element which is smaller than the key
            else{
                res = root;
                root = root.right;
            }
        }
        return (res == null) ? -1 : res.data;
    } 
 
}
```
---
### Insert a node in a BST <a name="insert"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class Solution
{
    //Function to insert a node in a BST.
    Node insert(Node root, int Key)
    {
        // your code here
        if(root == null){
            return new Node(Key);
        }
        if(root.data == Key) return root;
        else if(root.data > Key)
            root.left = insert(root.left, Key);
        else
            root.right = insert(root.right, Key);
        return root;
    }
}
```
---
### Lowest Common Ancestor in a BST <a name="lca"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class BST
{   
    //Function to find the lowest common ancestor in a BST. 
	Node LCA(Node root, int n1, int n2)
	{
        // code here.    
        if(root == null) return null;
        if(root.data > n1 && root.data > n2)
            return LCA(root.left, n1, n2);
        else if(root.data < n1 && root.data < n2)
            return LCA(root.right, n1, n2);
        else return root;
    }
    
}
```
---
### Minimum Element in a BST <a name="minimumElement"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(1) |
```java
class Tree
{
    //Function to find the minimum element in the given BST.
    int minValue(Node node)
    {
        if(node == null) return -1;
        Node curr = node;
        while(curr.left != null){
            curr = curr.left;
        }
        return curr.data;
    }
}
```
---
### Pair Sum in a BST <a name="pairsum"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class GFG 
{
    //Function to check if any pair exists in BST
    //whose sum is equal to given value.
    static boolean findPair(Node root, int X) 
    {
        // Your code
        TreeSet<Integer> set = new TreeSet<Integer>();
        return findPairUtil(root, X, set);
    }
    public static boolean findPairUtil(Node root, int X, TreeSet<Integer> set){
        if(root == null) return false;
        //if pair exist in left subtree return true
        if(findPairUtil(root.left, X, set) == true) return true;
        //if not then, if the root data's other pair exists in the set
        if(set.contains(X - root.data) == true) return true;
        //else add the root data in the set
        set.add(root.data);
        //check if the pair exist in the right subtree
        return findPairUtil(root.right, X, set);
    }
}
```
---
### Print BST elements in a given range <a name="bstInRange"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(h) |
```java
class Solution
{   
    //Function to return a list of BST elements in a given range.
	public static ArrayList<Integer> printNearNodes(Node root,int low,int high) {
        // code here.
        ArrayList<Integer> res = new ArrayList<Integer>();
        fillArray(root, low, high, res);
        return res;
    }
    
    public static void fillArray(Node root, int l, int h, ArrayList<Integer> arr){
        if(root == null) return;
	//if root is greater than high then search left subtree
        if(root.data > h) fillArray(root.left, l, h, arr);
	//if root is smaller than low then search right subtree
        else if(root.data < l) fillArray(root.right, l, h, arr);
	//
        else{
            fillArray(root.left, l, root.data, arr);
            arr.add(root.data);
            fillArray(root.right, root.data, h, arr);
        }
    }
}
```
---
### Search a node in a BST <a name="search"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(h) | O(h) |
```java
class BST
{
    //Function to search a node in BST.
    boolean search(Node root, int x)
    {
	    // Your code here
	    if(root == null) return false;
	    if(root.data == x) return true;
	    else if(root.data > x)
	        return search(root.left, x);
	   else return search(root.right, x);
    }
}
```
---
---
### Top View of Binary Tree <a name="topview"></a>
##### If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(n) |
```java
class Solution
{
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    static class Pair{
        Node node;
        int hd;
        Pair(Node n, int h){
            node = n;
            hd = h;
        }
    }
    
    static ArrayList<Integer> topView(Node root)
    {
        // add your code
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<Pair> q = new LinkedList<Pair>();
        TreeMap<Integer, Integer> mp = new TreeMap<Integer, Integer>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()){
            Pair curr = q.poll();
            Node node = curr.node;
            int hd = curr.hd;
            //if the node value corresponding the hd is not present in the map 
            //then only put the value inside the treemap otherwise ignore
            if(!mp.containsKey(hd)){
                mp.put(hd,node.data);
            }
            if(node.left != null) q.add(new Pair(node.left,hd-1));
            if(node.right != null) q.add(new Pair(node.right, hd+1));
        }
        for(Map.Entry<Integer, Integer> e : mp.entrySet()){
            res.add(e.getValue());
        }
        return res;
    }
}
```
---
### Vertical Traversal of Binary Tree <a name="verticalTraversal"></a>
##### If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| BST | Java | O(n) | O(n) |
```java
class Solution
{
    //Function to find the vertical order traversal of Binary Tree.
    static class Pair{
        Node node;
        int hd;
        Pair(Node n, int h){
            node = n;
            hd = h;
        }
    }
    static ArrayList <Integer> verticalOrder(Node root)
    {
        // add your code here
        Queue<Pair> q = new LinkedList<Pair>();
        TreeMap<Integer, ArrayList<Integer>> mp = new TreeMap<Integer, ArrayList<Integer>>();
        q.add(new Pair(root, 0));
        while(!q.isEmpty()){
            Pair curr = q.poll();
            Node node = curr.node;
            int hd = curr.hd;
            if(!mp.containsKey(hd)){
                ArrayList lt = new ArrayList<Integer>();
                mp.put(hd,lt);
            }
            mp.get(hd).add(node.data);
            if(node.left != null) q.add(new Pair(node.left,hd-1));
            if(node.right != null) q.add(new Pair(node.right, hd+1));
        }
        
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(Map.Entry<Integer, ArrayList<Integer>> e : mp.entrySet()){
            res.addAll(e.getValue());
        }
        return res;
    }
}
```
---
