class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long b, long long e){
        if(e==0)
            return 1;
        if(e==1)
            return b%mod;
        long long tmp = power(b, e/2)%mod;
        if(e%2){
            tmp = (tmp*tmp)%mod;
            return ((b%mod) * tmp)%mod;
        }
        else 
            return (tmp*tmp)%mod;
    }
    int minNonZeroProduct(int p) {
        long long mx = pow(2, p);
        mx--;
        long long tot = power(mx-1, mx/2);
        return (tot*(mx%mod))%mod;


    }
};