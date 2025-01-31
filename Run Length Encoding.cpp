class Solution {
  public:
    string encode(string s) {
        // code here
        int cnt = 1;
        int n = s.length();
        string res = "";
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1])
                cnt++;
            else{
                res += s[i-1] + to_string(cnt);
                cnt = 1;
            }
        }
        res += s[n-1] + to_string(cnt);
        return res;
    }
};