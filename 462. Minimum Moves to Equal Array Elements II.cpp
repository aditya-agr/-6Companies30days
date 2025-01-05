class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n/2];
        long long res = 0;
        for(int x : nums)
            res += abs(med - x);
        return res;
    }
};