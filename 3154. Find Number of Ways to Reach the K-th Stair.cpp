class Solution {
public:
    int solve(int curr, int k, int jump, int backJump, unordered_map<string, int> &mp){
        if(curr > k+1)
            return 0;
        string key = to_string(curr)+"#"+to_string(jump)+"#"+to_string(backJump);
        if(mp.find(key) != mp.end())
            return mp[key];
        int way = 0;
        if(curr == k)
            way++;
        way += solve(curr+pow(2, jump), k, jump+1, 1, mp);
        if(backJump){
            way += solve(curr-1, k, jump, 0, mp);
        }
        return mp[key] = way;
    }
    int waysToReachStair(int k) {
        unordered_map<string, int> mp;
        return solve(1, k, 0, 1, mp);
    }
};