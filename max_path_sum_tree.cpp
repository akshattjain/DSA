class Solution {
public:
    int sum(TreeNode* root,int& maxi){
        if(root==NULL){
            return 0;
        }

        int lsum=max(0,sum(root->left,maxi));
        int rsum=max(0,sum(root->right,maxi));

        maxi=max(maxi,lsum+rsum+root->val);
        
        return max(lsum, rsum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;

        sum(root,maxi);

        return maxi;
    }
};
