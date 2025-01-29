class Solution {
public:
    vector<int> lps(string &p){
        int n = p.length();
        vector<int> l(n);
        int i=1, len=0;
        while(i<n){
            if(p[i] == p[len]){
                len++; 
                l[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    l[i] = 0;
                    i++;
                }
                else
                    len = l[len-1];
            }
        }
        return l;
    }
    vector<int> kmp(string &s, string &pat){
        vector<int> lps_pat = lps(pat);
        int n = s.size();
        int m = pat.size();
        int i=0, j=0;
        vector<int> res;
        while(i<n){
            if (s[i]==pat[j]){
                i++; j++;
            }
            if(j==m){
                res.push_back(i-j);
                j = lps_pat[j-1];
            }
            else if(i<n && s[i]!=pat[j]){
                if(j==0)
                    i++;
                else
                    j = lps_pat[j-1];
            }
        }
        return res;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> kmpa = kmp(s, a);
        vector<int> kmpb = kmp(s, b);
        if(kmpa.empty() || kmpb.empty())
            return {};
        vector<int> res;
        for(int &x : kmpa){
            int l = max(0, x-k);
            int r = min(n-1, x+k);
            auto it = lower_bound(kmpb.begin(), kmpb.end(), l);
            if(it != kmpb.end() && *it <= r) 
                res.push_back(x);
            
        }
        return res;
    }
};