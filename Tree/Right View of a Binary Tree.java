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