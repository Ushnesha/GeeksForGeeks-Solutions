#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

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