#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
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
