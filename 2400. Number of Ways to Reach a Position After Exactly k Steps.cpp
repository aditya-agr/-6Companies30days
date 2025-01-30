class Solution {
public:
    int dp[3002][1001];
    int mod = 1e9+7;
    int solve(int s, int e, int k){
        if(s==e && k==0)
            return 1;
        if(k<=0)
            return 0;
        if(dp[s+1001][k] != -1)
            return dp[s+1001][k];
        int left = solve(s-1, e, k-1)%mod;
        int right = solve(s+1, e, k-1)%mod;
        return dp[s+1001][k] = (left + right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k);
    }
};