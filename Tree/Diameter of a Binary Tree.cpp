#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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