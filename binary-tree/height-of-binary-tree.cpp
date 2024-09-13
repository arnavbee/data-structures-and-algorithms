  int maxDepth(TreeNode* root) {
        if(root == NULL)
        return NULL;


        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        int ans = max(left, right) + 1;
        return ans;
        
    }