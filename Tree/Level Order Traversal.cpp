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