class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res(n);
        int ed = n-1;
        for(int i=1; i<n; i+=2)
            res[i] = nums[ed--];
        for(int i=0; i<n; i+=2)
            res[i] = nums[ed--];
        nums = res;
    }
};