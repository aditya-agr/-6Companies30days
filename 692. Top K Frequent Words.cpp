class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string word : words)
            mp[word]++;
        
        auto comp = [](const pair<int, string> &a, const pair<int, string> &b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };

        vector<pair<int, string>> idx;
        for(auto it : mp)
            idx.push_back({it.second, it.first});
        sort(idx.begin(), idx.end(), comp);
        vector<string> res;
        for(int i=0; i<k; i++)
            res.push_back(idx[i].second);
        return res;
    }
};