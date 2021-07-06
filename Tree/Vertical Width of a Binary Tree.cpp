//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to find the vertical width of a Binary Tree.
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