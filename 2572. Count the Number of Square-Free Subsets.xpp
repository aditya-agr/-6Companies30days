class Solution {
public:
    unordered_map<int, int> freq;
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29};
    int dp[1001][1024];
    const int MOD = 1e9 + 7;  
    
    int check(int mask, int num){
        for(int i=0; i<10; i++){
            int cnt = 0;
            while(num%prime[i]==0){
                num /= prime[i];
                cnt++;
            }
            if(cnt>1 || (cnt==1 && mask&(1<<i)))
                return -1;
            if(cnt)
                mask = mask|(1<<i);
        }
        return mask;
    }
    
    int solve(int i, int mask, vector<int> &vec){
        if(i==vec.size())
            return 1;
        if(dp[i][mask] != -1)
            return dp[i][mask];
            
        int notake = solve(i+1, mask, vec) % MOD;
        int take = 0;
        int temp = check(mask, vec[i]);
        if(vec[i]!=1 && temp!=-1) 
            take = (1LL * freq[vec[i]] * solve(i+1, temp, vec)) % MOD;
        return dp[i][mask] = (take + notake) % MOD; 
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        unordered_set<int> st;
        for(int x : nums){
            freq[x]++;
            st.insert(x);
        }
        vector<int> vec(st.begin(), st.end());
        int n = vec.size();
        memset(dp, -1, sizeof(dp));
        
        int wayo = (solve(0, 0, vec) - 1 + MOD) % MOD;
        int cnt1 = freq[1];
        int way1 = 0;
        long long pow2 = 1;
        for(int i = 0; i < cnt1; i++) {
            pow2 = (pow2 * 2) % MOD;
        }
        way1 = (pow2 - 1 + MOD) % MOD;
        
        long long result = wayo;
        result = (result + way1) % MOD;
        result = (result + (1LL * wayo * way1) % MOD) % MOD;
        
        return result;
    }
};