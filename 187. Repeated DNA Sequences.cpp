class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st, res;
        int n = s.size();
        for(int i=0; i<=n-10; i++){
            string curr = s.substr(i, 10);
            if(st.find(curr) != st.end())
                res.insert(curr);
            st.insert(curr);
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};