class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(k--){
            int tp = pq.top();
            tp++;
            pq.pop();
            pq.push(tp);
        }
        int mod = 1e9+7;
        long long res = 1;
        while(!pq.empty()){
            int tp = pq.top();
            pq.pop();
            res = (res*tp)%mod;
        }
        return res;
    }
};