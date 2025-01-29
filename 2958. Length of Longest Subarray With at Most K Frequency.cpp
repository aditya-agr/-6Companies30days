class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        unordered_map<int, int> mp;
        int res = 0;
        while(j<n){
            int x = nums[j];
            mp[x]++;
            while(i<j && mp[x] > k){
                mp[nums[i]]--;
                i++;
            }
            int curr = j-i+1;
            res = max(res, curr);
            j++;
        }
        return res;
    }
};