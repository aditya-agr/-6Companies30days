class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(int x : arr1){
            int l = x-d;
            int r = x+d;
            auto low = lower_bound(arr2.begin(), arr2.end(), l);
            if(low == arr2.end() || *low > r)
                ans++;
        }
        return ans;
    }
};