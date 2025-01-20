class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, tot = 0;
        for(int i=0; i<n; i++){
            tot += i*nums[i];
            sum += nums[i];
        } 
        int maxi = tot;
        for(int i=n-1; i>=0; i--){
            tot = tot + sum - n*nums[i];
            maxi = max(maxi, tot);
        }
        return maxi; 
    }
};