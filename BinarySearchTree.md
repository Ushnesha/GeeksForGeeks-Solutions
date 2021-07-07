## Binary Search Tree
### Table of contents
1. [Insert node in a BST](#insert)
---
### Insert node in a BST <a name="insert"></a>
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
