class Solution {
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node root) {
        // Your code here
        int maxWidth = 0;
        if(root == null) return maxWidth;
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            int qSize = q.size();
            maxWidth = Math.max(maxWidth, qSize);
            while(qSize > 0){
                Node n = q.poll();
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
                qSize--;
            }
        }
        return maxWidth;
    }
}