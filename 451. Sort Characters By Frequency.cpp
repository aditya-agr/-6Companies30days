class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c : s)
            mp[c]++;
        vector<pair<int,int>> idx;
        for(auto it : mp)
            idx.push_back({it.second, it.first});
        sort(idx.rbegin(), idx.rend());
        string res = "";
        for(auto x : idx)
            res.append(x.first, x.second);
        return res;

    }
};