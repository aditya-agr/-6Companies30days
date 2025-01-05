class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                bool flag = true;
                int last = -1;
                for(int k=0; k<n; k++){
                    if(k>=i && k<=j) continue;
                    if(last >= nums[k]){
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }
                cnt += flag;
            }
        }
        return cnt;
    }
};