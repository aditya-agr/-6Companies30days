class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int mxv=1, mxh=1, c=1;
        int N = hBars.size();
        for(int i=1; i<N; i++){
            if(hBars[i] == hBars[i-1]+1)
                c++;
            else
                c=1;
            mxh = max(mxh, c);
        }
        c=1;
        int M = vBars.size();
        for(int i=1; i<M; i++){
            if(vBars[i] == vBars[i-1]+1)
                c++;
            else
                c=1;
            mxv = max(mxv, c);
        }
        int side = min(mxv+1, mxh+1);
        return side*side;
    }
};