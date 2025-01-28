/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dis, res;
    vector<int> solve(TreeNode* root){
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {1};

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        for(int x : l)
            for(int y : r)
                if(x+y <= dis)
                    res++;
        
        vector<int> p;
        for(int x : l)
            if(x+1<dis) p.push_back(x+1);
        for(int y : r)
            if(y+1<dis) p.push_back(y+1);

        return p;
    }

    int countPairs(TreeNode* root, int distance) {
        dis = distance;
        res = 0;
        solve(root);
        return res;
    }
};