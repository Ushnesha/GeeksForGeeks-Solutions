# GeeksForGeeks-Solutions
## Tree
### Table of contents
1. [Check for Balance](#checkForBalance)
2. [Children Sum Parent](#childrenSumParent)
3. [Determine if two trees are identical](#ifIdentical)
4. [Diameter of a Binary Tree](#diameter)
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
| Tree | CPP | O(n) | O(h) |

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

