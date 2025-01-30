class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(), access_times.end());
        vector<string> res;
        int n = access_times.size();
        
        for(int i=2; i<n; i++){
            int x = stoi(access_times[i][1]);
            int x2 = stoi(access_times[i-2][1]);
            if(access_times[i][0] == access_times[i-2][0] && x-x2 < 100){
                if(res.empty() || res.back() != access_times[i][0])
                    res.push_back(access_times[i][0]);
            }
        }
        return res;
    }
};