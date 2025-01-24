class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++)
            vec.push_back({aliceValues[i]+bobValues[i], i});
        
        sort(vec.rbegin(), vec.rend());
        int a=0, b=0;
        for(int i=0; i<n; i++){
            int idx = vec[i].second;
            a += aliceValues[idx];
            i++;
            if(i==n) break;
            idx = vec[i].second;
            b += bobValues[idx];
        }
        if(a>b) return 1;
        if(a<b) return -1;
        return 0;
        
    }
};