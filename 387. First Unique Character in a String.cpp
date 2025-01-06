class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> idx(26);
        for(char c : s)
            idx[c-'a']++;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(idx[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};