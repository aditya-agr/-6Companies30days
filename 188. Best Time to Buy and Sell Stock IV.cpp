class Solution {
public:
    int solve(vector<int>& prices, int i, int cnt, int buy, int& k,
              vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || cnt >= k)
            return 0;
        if(dp[i][cnt][buy] != -1)
            return dp[i][cnt][buy];
        if (buy)
            return dp[i][cnt][buy] = max(-prices[i] + solve(prices, i + 1, cnt, 0, k, dp), solve(prices, i + 1, cnt, 1, k, dp));
        else
            return dp[i][cnt][buy] = max(prices[i] + solve(prices, i + 1, cnt + 1, 1, k, dp), solve(prices, i + 1, cnt, 0, k, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        int res = solve(prices, 0, 0, 1, k, dp);
        return res;
    }
};