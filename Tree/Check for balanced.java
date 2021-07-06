#include <bits/stdc++.h>
using namespace std;

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