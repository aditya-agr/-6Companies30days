class Solution {
public:
    vector<string> res;
    void solve(string &digits, int d, string &curr, unordered_map<char, vector<string>> &mp){
        if(d == digits.length()){
            res.push_back(curr);
            return;
        }
        for(string &s : mp[digits[d]]){
            curr.append(s);
            solve(digits, d+1, curr, mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        unordered_map<char, vector<string>> mp;
        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};

        string curr;
        solve(digits, 0, curr, mp);
        return res;
    }
};