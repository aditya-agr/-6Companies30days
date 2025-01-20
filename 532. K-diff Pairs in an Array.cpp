class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int cnt = 0, cnt0 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                if(i==n-1 || nums[i]!=nums[i+1]) cnt0++;
                continue;
            }
            if(mp[nums[i]-k])
                cnt++;
            mp[nums[i]]++;
        }
        if(k==0)
            return cnt0;
        return cnt;
    }
};