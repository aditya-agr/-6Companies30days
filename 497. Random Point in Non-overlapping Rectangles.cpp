class Solution {
public:
    vector<int> idx;
    vector<vector<int>> rec;
    Solution(vector<vector<int>>& rects) {
        rec = rects;
        for(auto v : rects){
            int curr = (v[2]-v[0]+1) * (v[3]-v[1]+1);
            idx.push_back(curr);
        }
        int n = idx.size();
        for(int i=1; i<n; i++)
            idx[i] += idx[i-1]; 
    }
    
    vector<int> pick() {
        int rnd = rand() % idx.back();
        int i = upper_bound(idx.begin(), idx.end(), rnd)  - idx.begin();
        vector<int> curr = rec[i];
        int x = rand()%(curr[2]-curr[0]+1) + curr[0];
        int y = rand()%(curr[3]-curr[1]+1) + curr[1];
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */