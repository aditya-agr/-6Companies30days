class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int miss=0, rep=0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int idx = abs(arr[i])-1;
            if(arr[idx]<0)
                rep = idx+1;
            else
                arr[idx] *= -1;
        }
        for(int i=0; i<n; i++)
            if(arr[i]>0)
                miss = i+1;
        return {rep, miss};
    }
};