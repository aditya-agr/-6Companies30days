class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> idx(n);
        for(int i=0; i<n; i++)
            idx[i] = abs(s[i]-t[i]);
        int i=0, j=0;
        int curr = 0, res = 0;
        while(j<n){
            curr += idx[j];
            while(curr > maxCost){
                curr -= idx[i];
                i++;
            }    
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};