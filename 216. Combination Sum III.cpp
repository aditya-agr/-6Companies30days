class Solution {
public:
    void solve(int u, int k, int n, vector<int> &curr, vector<vector<int>> &res){
        if(n<0 || k<0)
            return;
        if(n==0 && k==0){
            res.push_back(curr);
            return;
        }
        for(int i=u; i<10; i++){
            curr.push_back(i);
            solve(i+1, k-1, n-i, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(1, k, n, curr, res);
        return res;
    }
};