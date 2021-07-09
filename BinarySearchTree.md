## Binary Search Tree
### Table of contents
1. [Delete a node from BST](#delete)
2. [Find Common nodes in two BSTs](#findCommon)
3. [Insert a node in a BST](#insert)
4. [Lowest Comon Ancestor in a BST](#lca)
5. [Minimum element in a BST](#minimumElement)
6. [Search a node in a BST](#search)
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
