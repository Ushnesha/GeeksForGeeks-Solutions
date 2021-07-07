## Tree
### Table of contents
1. [Binary Tree to CDLL](#treeToCDll) 
2. [Binary Tree to DLL](#treeToDll) 
3. [Check for Balance](#checkForBalance)
4. [Check if Subtree](#ifSubtree)
5. [Children Sum Parent](#childrenSumParent)
6. [Connect Nodes at same level](#connectNodesatSameLevel)
7. [Construct Binary Tree from Parent Array](#treeFromArray)
8. [Count number of subtrees having given sum](#countSubtrees)
9. [Determine if two trees are identical](#ifIdentical)
10. [Diameter of a Binary Tree](#diameter)
11. [Foldable Binary Tree](#foldable)
12. [Height of a Binary Tree](#height)
13. [Left View of a Binary Tree](#leftView)
14. [Level Order Traversal](#levelorder)
15. [Level Order Traversal in Spiral Form](#spiral)
16. [Lowest Common Ancestor](#lca)
17. [Make a Binary Tree from Linked List](#treeFromList)
18. [Maximum Difference between Node and its Ancestor](#maxDiffNodeandAncestor)
19. [Maximum Path Sum from any node](#maxPathSum)
20. [Maximum Sum of Non adjacent nodes of a Binary Tree](#maxSumNonAdj)
21. [Maximum Width of a Binary Tree](#maxWidth)
22. [Mirror Tree](#mirror)
23. [Right View of a Binary Tree](#rightView)
24. [Serialize and Deserialize a Binary Tree](#serializeDeserialize)
25. [Tree from Postorder and Inorder](#treeFromPostandIn)
26. [Vertical Width of a Binary Tree](#verticalWidth)
27. [Zig Zag Traversal](#zigzag)
---
### Node declaration in java
```java
class Node{
  int data;
  Node left, right;
  Node(int val){
    data = val;
  }
}
```

### Node declaration in CPP
```cpp
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
```
---
### Binary Tree to CDLL <a name="treeToCDll"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Solution
{ 
    //Function to convert binary tree into circular doubly linked list.
    Node bTreeToClist(Node root)
    {
        //your code here
        if(root == null) return null;
        Node left = bTreeToClist(root.left);
        Node right = bTreeToClist(root.right);
        root.left = root.right = root;
        return concatenate(concatenate(left, root), right);
    }
    
    Node concatenate(Node leftList, Node rightList){
        if(leftList == null) return rightList;
        if(rightList == null) return leftList;
        Node leftLast = leftList.left;
        Node rightLast = rightList.left;
        leftLast.right = rightList;
        rightList.left = leftLast;
        leftList.left = rightLast;
        rightLast.right = leftList;
        return leftList;
    }
    
}
```
---
### Binary Tree to DLL <a name="treeToDll"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Solution
{
    //Function to convert binary tree to doubly linked list and return it.
    Node prev = null;
    // Node head = null;
    Node bToDLL(Node root)
    {
	//  Your code here	
	    if(root == null) return root;
	    Node head = bToDLL(root.left);
	    if(prev == null) head = root;
	    else{
            root.left = prev;
            prev.right = root;
        }
        prev = root;
        bToDLL(root.right);
        return head;
    }
}
```
---
### Check for Balance <a name="checkForBalance"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(h) |

```cpp
int height(Node* root){
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh == -1 || rh == -1) return -1;
    return abs(lh-rh)>1 ? -1 : 1+max(lh, rh);
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    return height(root) == -1 ? 0 : 1;
}
```
---
### Check if Subtree <a name="ifSubtree"></a>
##### Check if a given tree S is a subtree of another T.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n^2) | O(h) |

```cpp
class Solution {
    public static boolean isSubtree(Node T, Node S) {
        if(S == null) return true;
        if(T == null) return false;
        if(isIdentical(T,S) == true) return true;
        return (isSubtree(T.left,S) || isSubtree(T.right, S));
    }
    
    public static boolean isIdentical(Node T, Node S){
        if(T == null && S == null) return true;
        if(T == null || S == null) return false;
        return T.data == S.data && isIdentical(T.left, S.left) && isIdentical(T.right, S.right);
    }
}
```
---
### Children Sum Parent <a name="childrenSumParent"></a>
##### Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(h) |

```cpp
int isSumProperty(Node *root)
{
 // Add your code here
 if(root == NULL) return 1;
 if(root->left == NULL && root->right == NULL) return 1;
 int sum = 0;
 if(root->left) sum+=root->left->data;
 if(root->right) sum+=root->right->data;
 return sum==root->data && isSumProperty(root->left) && isSumProperty(root->right);
}
```
---
### Connect Nodes at Same Level <a name="connectNodesatSameLevel"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(n) |
```java
class Solution
{
    //Function to connect nodes at same level.
    public void connect(Node root)
    {
        // Your code goes here.
        if(root == null) return;
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            int qSize = q.size();
            Node prev = null;
            while(qSize>0){
                Node n = q.remove();
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
                if(prev == null){
                    prev = n;
                }
                else{
                    prev.nextRight = n;
                    prev = n;
                }
                qSize--;
            }
            prev.nextRight = null;
        }
    }
}
```
---
### Construct Binary Tree from Parent Array <a name="treeFromArray"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(n) |
```java
class GfG
{
    //Function to construct binary tree from parent array.
    public static Node createTree(int parent[], int N)
    {
        //Your code here
        HashMap<Integer, ArrayList<Integer>> parents = new HashMap<Integer, ArrayList<Integer>>();
        for(int i = 0; i < N; i++){
            if(parents.get(parent[i]) == null)
                parents.put(parent[i], new ArrayList<Integer>());
            parents.get(parent[i]).add(i);
        }
        
        Node root = new Node(parents.get(-1).get(0));
        
        createTreeUtil(parents, root);
        return root;
    }
    
    public static void createTreeUtil(HashMap<Integer, ArrayList<Integer>> mp, Node root){
        if(root == null) return;
        ArrayList<Integer> arr = mp.get(root.data);
        if(arr == null) return;
        if(arr.size() == 1){
            root.left = new Node(arr.get(0));
        }
        else{
            root.left = new Node(arr.get(0));
            root.right = new Node(arr.get(1));
        }
        createTreeUtil(mp, root.left);
        createTreeUtil(mp, root.right);
    }
    
}
```
---
### Count number of subtrees having given sum <a name="countSubtrees"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Tree
{
    //Function to count number of subtrees having sum equal to given sum.
    int count = 0;
    int countSubtreesWithSumX(Node root, int X)
    {
	//Add your code here.
	    countSubtreesWithSumXUtil(root, X);
	    return count;
    }
    int countSubtreesWithSumXUtil(Node root, int X)
    {
	//Add your code here.
	    if(root == null) return 0;
	    int leftCount = countSubtreesWithSumXUtil(root.left, X);
	    int rightCount = countSubtreesWithSumXUtil(root.right, X);
	    if(leftCount + rightCount + root.data == X) count++;
	    return leftCount + rightCount + root.data;
    }
}
```
---
### Determine if two trees are Identical <a name="ifIdentical"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |

```java
class Solution
{
    //Function to check if two trees are identical.
	boolean isIdentical(Node root1, Node root2)
	{
	    // Code Here
	    if(root1 == null && root2 == null) return true;
	    if((root1 == null && root2 != null) || (root1 != null && root2 == null)) return false;
	    return root1.data == root2.data && isIdentical(root1.left, root2.left) && isIdentical(root1.right, root2.right);
	}
	
}
```
---
### Diameter of a Binary Tree <a name="diameter"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(h) | O(h) |

```cpp
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int maxD = 0;
    
    int diameterUtil(Node* root) {
        // Your code here
        if(root == NULL) return 0;
        int lh = diameterUtil(root->left);
        int rh = diameterUtil(root->right);
        maxD = max(maxD, lh+rh+1);
        return 1+max(lh,rh);
        
    }
    
    int diameter(Node* root) {
        // Your code here
        diameterUtil(root);
        return maxD;
        
    }
};
```
---
### Foldable Binary Tree <a name="foldable"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Tree
{
    //Function to check whether a binary tree is foldable or not.
    boolean IsFoldable(Node node) 
	{ 
		// your code 
		if(node == null) return true;
		return isSimilar(node.left, node.right);
	} 
	
	boolean isSimilar(Node node1, Node node2){
	    if(node1 == null && node2 == null) return true;
	    if(node1 == null || node2 == null) return false;
	    return isSimilar(node1.left, node2.right) && isSimilar(node1.right, node2.left);
	}
}
```
---
### Height of a Binary Tree <a name="height"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(h) | O(h) |
```cpp
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node == NULL) return 0;
        return 1+max(height(node->left),height(node->right));
    }
};
```
---
### Left View of a Binary Tree <a name="leftView"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Tree
{
    //Function to return list containing elements of left view of binary tree.
    int maxLevel = 0;
    void leftViewUtil(Node root, ArrayList<Integer> vec, int level){
        if(root == null) return;
        if(maxLevel < level){
            vec.add(root.data);
            maxLevel = level;
        }
        leftViewUtil(root.left, vec, level+1);
        leftViewUtil(root.right, vec, level+1);
    }

    ArrayList<Integer> leftView(Node root)
    {
      // Your code here
      ArrayList<Integer> arr = new ArrayList<Integer>();
      leftViewUtil(root, arr, 1);
      return arr;
    }
}
```
---
### Level Order Traversal of a Binary Tree <a name="levelorder"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(Width of the tree) |
```cpp
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> res;
      if(node == NULL) return vector<int>();
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          int qSize = q.size();
          while(qSize--){
              Node* n = q.front();
              q.pop();
              res.push_back(n->data);
              if(n->left) q.push(n->left);
              if(n->right) q.push(n->right);
          }
      }
      return res;
    }
};
```
---
### Level Order Traversal of a Binary Tree in Spiral Form <a name="spiral"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(Width of the tree) |
```cpp
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> res;
    if(root==NULL) return vector<int>();
    stack<int> st;
    queue<Node*> q;
    q.push(root);
    bool rev = true;
    while(!q.empty()){
      int qSize = q.size();
      while(qSize--){
          Node* n = q.front();
          q.pop();
          if(rev) st.push(n->data);
          else res.push_back(n->data);
          if(n->left) q.push(n->left);
          if(n->right) q.push(n->right);
      }
      if(rev){
          while(!st.empty()){
              res.push_back(st.top());
              st.pop();
          }
      }
      rev=!rev;
    }
    return res;
}
```
---
### Lowest Common Ancestor <a name="lca"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(h) |
```cpp
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       if(root == NULL) return NULL;
       if(root->data == n1 || root->data == n2) return root;
       Node* lcal = lca(root->left, n1, n2);
       Node* lcar = lca(root->right, n1, n2);
       if(lcal != NULL && lcar != NULL) return root;
       if(lcal != NULL) return lcal;
       else return lcar;
    }
};
```
---
### Make a Binary Tree from a Linked List <a name="treeFromList"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(h) |
```cpp
void convert(Node *head, TreeNode *&root) {
    // Your code here
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    head=head->next;
    q.push(root);
    while(!q.empty() && head){
        int qSize = q.size();
        while(qSize-- && head){
            TreeNode* node = q.front();
            q.pop();
            node->left = new TreeNode(head->data);
            q.push(node->left);
            head = head->next;
            if(head){
                node->right = new TreeNode(head->data);
                q.push(node->right);
                head=head->next;
            }
        }
    }
    
}
```
---
### Maximum difference between node and its ancestor <a name="maxDiffNodeandAncestor"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Tree
{
    //Function to return the maximum difference between any 
    //node and its ancestor.
    int maxN = Integer.MIN_VALUE;
    int maxDiff(Node root)
    {
        //your code here
        if(root == null) return maxN;
        maxDiffUtil(root.left, root, 0);
        maxDiffUtil(root.right, root, 0);
        return maxN;
        
    }
    
    void maxDiffUtil(Node root, Node par, int diff){
        if(root == null) return;
        int localDiff = par.data - root.data;
        int max_local = Math.max(localDiff, localDiff+diff);
        maxN = Math.max(max_local, maxN);
        maxDiffUtil(root.left, root, max_local);
        maxDiffUtil(root.right, root, max_local);
    }
}
```
---
### Maximum Path Sum from any node <a name="maxPathSum"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Solution
{
    //Function to return maximum path sum from any node in a tree.
    int maxS = Integer.MIN_VALUE;
    int findMaxSum(Node node)
    {
        //your code goes here
        maxSum(node);
        return maxS;
    }
    
    int maxSum(Node node){
        if(node == null) return 0;
        int left = maxSum(node.left);
        int right = maxSum(node.right);
        int max_single = Math.max(Math.max(left,right) + node.data, node.data);
        int max_top = Math.max(max_single, left+right+node.data);
        maxS = Math.max(maxS, max_top);
        return max_single;
    }
    
}
```
---
### Maximum sum of non adjacent nodes of a Binary Tree <a name="maxSumNonAdj"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class GFG
{
    //Function to return the maximum sum of non-adjacent nodes.
    static int getMaxSum(Node root)
    {
        // add your code here
        if(root == null) return 0;
        HashMap<Node, Integer> mp = new HashMap<Node, Integer>();
        return getMaxUtil(root, mp);
    }
    
    static int getMaxUtil(Node root, HashMap<Node, Integer> mp){
        if(root == null){
            return 0;
        }
        if(mp.containsKey(root)) return mp.get(root);
        int incl = root.data + sumOfGrandChildren(root, mp);
        int excl = getMaxUtil(root.left, mp) + getMaxUtil(root.right, mp);
        mp.put(root, Math.max(incl, excl));
        return mp.get(root);
    }
    
    static int sumOfGrandChildren(Node node, HashMap<Node, Integer> mp){
        int sum = 0;
        if(node.left != null){
            sum+=getMaxUtil(node.left.left, mp) + getMaxUtil(node.left.right, mp);
        }
        if(node.right != null){
            sum+=getMaxUtil(node.right.left, mp) + getMaxUtil(node.right.right, mp);
        }
        return sum;
    }
}
```
---
### Maximum Width of a Binary Tree <a name="maxWidth"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(h) | O(Width of a tree) |
```java
class Solution {
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node root) {
        // Your code here
        int maxWidth = 0;
        if(root == null) return maxWidth;
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            int qSize = q.size();
            maxWidth = Math.max(maxWidth, qSize);
            while(qSize > 0){
                Node n = q.poll();
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
                qSize--;
            }
        }
        return maxWidth;
    }
}
```
---
### Mirror of a Binary Tree <a name="mirror"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(h) |
```cpp
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node) return;
        mirror(node->left);
        mirror(node->right);
        Node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        
    }
};
```
---
### Right View of a Binary Tree <a name="rightView"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(h) |
```java
class Solution{
    //Function to return list containing elements of right view of binary tree.
    int maxLevel = 0;
    void rightViewUtil(Node root, ArrayList<Integer> vec, int level){
        if(root == null) return;
        if(maxLevel < level){
            vec.add(root.data);
            maxLevel = level;
        }
        rightViewUtil(root.right, vec, level+1);
        rightViewUtil(root.left, vec, level+1);
    }
    ArrayList<Integer> rightView(Node node) {
        //add code here.
        ArrayList<Integer> arr = new ArrayList<Integer>();
        if(node == null) return arr;
        rightViewUtil(node, arr, 1);
        return arr;
    }
}
```
---
### Serialize and Deserialize a Binary Tree <a name = "serializeDeserialize"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(n) |
```java
class Tree 
{
    //Function to serialize a tree and return a list containing nodes of tree.
    int index = 0;
	public void serialize(Node root, ArrayList<Integer> A) 
	{
	    //code here
	    if(root == null){
	        A.add(-1);
	        return;
	    }
	    A.add(root.data);
	    serialize(root.left, A);
	    serialize(root.right, A);
	}
	
	//Function to deserialize a list and construct the tree.
    public Node deSerialize(ArrayList<Integer> A)
    {
        //code here
        if(A.get(index)==-1){
            index++;
            return null;
        }
        Node n = new Node(A.get(index++));
        n.left = deSerialize(A);
        n.right = deSerialize(A);
        return n;
    }
};
```
---
### Tree from Postorder and Inorder <a name = "treeFromPostandIn"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n^2) | O(h) |
```java
class GfG
{
    //Function to return a tree created from postorder and inoreder traversals.
    
    class Index{
        int i;
    }
    
    Node buildTree(int in[], int post[], int n) {
        // Your code here
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int i =0; i<n; i++){
            mp.put(in[i],i);
        }
        Index p = new Index();
        p.i = n-1;
        return buildTreeUtil(post, mp, 0, n-1, p);
    }
    
    Node buildTreeUtil(int post[],HashMap<Integer, Integer> mp, int si, int ei, Index index){
        if(si > ei){
            return null;
        }
        Node root = new Node(post[index.i]);
        int idx = mp.get(post[index.i]);
        index.i--;
        
        root.right = buildTreeUtil(post, mp, idx+1, ei, index);
        root.left = buildTreeUtil(post, mp, si, idx-1, index);
        return root;
    }
}
```
---
### Vertical Width of a Binary Tree <a name="verticalWidth"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | CPP | O(n) | O(h) |
```cpp
void verticalWidthUtil(Node* root, set<int> &st, int cur){
    if(root==NULL) return;
    verticalWidthUtil(root->left, st, cur-1);
    st.insert(cur);
    verticalWidthUtil(root->right, st, cur+1);
}


int verticalWidth(Node* root)
{
    // Code here
    set<int> res;
    verticalWidthUtil(root, res, 0);
    return res.size();
}
```
---
### Zig Zag Traversal <a name="zigzag"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Tree | Java | O(n) | O(n) |
```java
class GFG
{
    //Function to store the zig zag order traversal of tree in a list.
   
	ArrayList<Integer> zigZagTraversal(Node root)
	{
	    //Add your code here.
	    Queue<Node> q = new LinkedList<Node>();
	    Stack<Integer> st = new Stack<Integer>();
	    ArrayList<Integer> arr = new ArrayList<Integer>();
	     boolean reverse = false;
	     q.add(root);
	     while(!q.isEmpty()){
	         int qSize = q.size();
	         while(qSize > 0){
	             Node n = q.remove();
	             if(n.left != null) q.add(n.left);
	             if(n.right != null) q.add(n.right);
	             if(reverse){
	                 st.push(n.data);
	             }else{
	                 arr.add(n.data);
	             }
	                
	             qSize--;
	         }
	         if(reverse){
	             while(!st.empty()){
	                 arr.add(st.pop());
	             }
	         }
	         reverse = !reverse;
	     }
	     return arr;
	}
}
```
---
