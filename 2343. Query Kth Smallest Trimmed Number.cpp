class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].length();
        vector<vector<pair<string,int>>> vec(m+1, vector<pair<string,int>>(n));
        for(int i=1; i<=m; i++){
            for(int j=0; j<n; j++){
                string s = nums[j].substr(m-i);
                vec[i][j] = {s, j};
            }
            sort(vec[i].begin(), vec[i].end());
        }
        vector<int> res;
        for(vector<int> &q : queries){
            int k = q[0];
            int trim = q[1];
            res.push_back(vec[trim][k-1].second);
        }
        return res;
    }
};