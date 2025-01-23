class Solution {
public:
    int t[301];
    bool solve(int i, string &s, unordered_set<string> &st){
        int n = s.length();
        if(i == n)
            return true;
        if(t[i] != -1)
            return t[i];
        if(st.find(s.substr(i, n-i)) != st.end())
            return t[i] = true;
        
        for(int l=1; l<=n; l++){
            string curr = s.substr(i, l);
            if(st.find(curr) != st.end() && solve(i+l, s, st))
                return t[i] = true;
        }
        return t[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        memset(t, -1, sizeof(t));
        return solve(0, s, st);
    }
};