class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int i=0, j=0;
        int cnt = 0;
        while(j<m && i<n){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else
                j++;
        }
        return cnt;
    }
};