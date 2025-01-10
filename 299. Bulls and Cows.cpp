class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for(char c : secret)
            mp[c]++;
        int n = guess.size();
        int a=0, b=0;
        for(int i=0; i<n; i++){
            if(secret[i] == guess[i]){
                a++;
                mp[secret[i]]--;
            }
        }
        for(int i=0; i<n; i++){
            if(secret[i] != guess[i] && mp[guess[i]] > 0){
                b++;
                mp[guess[i]]--;
            }
        }
        string res = to_string(a)+"A"+to_string(b)+"B";
        return res;
    }
};