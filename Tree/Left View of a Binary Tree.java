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