/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr){
                s += to_string(curr->val)+",";
                q.push(curr->left);
                q.push(curr->right);
            }
            else
                s += "#,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        stringstream ss(data);
        string num;
        getline(ss, num, ',');
        TreeNode* root = new TreeNode(stoi(num));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(ss, num, ',');
            if(num != "#"){
                curr->left = new TreeNode(stoi(num));
                q.push(curr->left);
            }
            getline(ss, num, ',');
            if(num != "#"){
                curr->right = new TreeNode(stoi(num));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));