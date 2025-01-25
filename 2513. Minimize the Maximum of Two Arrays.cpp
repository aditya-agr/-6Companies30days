class Solution {
public:
    int minimizeSet(int div1, int div2, int cnt11, int cnt22) {
        long long d1=div1, d2=div2, cnt1=cnt11, cnt2=cnt22;
        long long l=0, r=1e15, ans=r;
        long long g = __gcd(d1, d2), lcm = (d1*d2)/g;
        if(d1==d2){
            long long rem = cnt1+cnt2;
            while(l<=r){
                long long mid = l+(r-l)/2;
                long long curr = mid - (mid/d1);
                if(rem<=curr){
                    ans = mid;
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
        }
        else{
            while(l<=r){
                long long mid = l + (r-l)/2;
                long long common = mid/lcm;
                long long c1 = (mid/d1) - common; 
                long long c2 = (mid/d2) - common; 
                long long curr = mid - (c1+c2+common);
                long long z1=cnt1, z2=cnt2;
                z1 -= min(z1, c2);
                z2 -= min(z2, c1);
                long long rem = z1+z2;

                if(rem<=curr){
                    ans = mid;
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
        }
        return ans;
    }
};