class Solution {
public:
    vector<int> getZarr(string str)
    {
        int n = str.length();
        int L, R, k;
        vector<int> Z(n);
        L = R = 0;
        for (int i = 1; i < n; ++i){
            if (i > R){
                L = R = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
            else{
                k = i-L;
                if (Z[k] < R-i+1)
                    Z[i] = Z[k];
                else{
                    L = i;
                    while (R<n && str[R-L] == str[R])
                        R++;
                    Z[i] = R-L;
                    R--;
                }
            }
        }
        return Z;
    }
    long long sumScores(string s) {
        vector<int> z = getZarr(s);
        long long tot = s.length();
        for(int x : z)
            tot += x;
        return tot;
    }
};