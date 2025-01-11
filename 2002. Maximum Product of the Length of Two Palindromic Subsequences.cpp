class Solution {
public:
    int lcs(string &a, string &b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) 
                    dp[i][j] = 0;
                else if(a[i-1] == b[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    int lps(string &s){
        string rs = s;
        reverse(rs.begin(), rs.end());
        return lcs(s, rs);
    }
    int maxProduct(string s) {
        int n = s.length(), res=1;
        for(int i=1; i<1<<n; i++){
            string x="", y="";
            for(int j=0; j<n; j++){
                if((1<<j)&i)
                    x += s[j];
                else
                    y += s[j];
            }
            res = max(res, lps(x)*lps(y));
        }
        return res;
    }
};
