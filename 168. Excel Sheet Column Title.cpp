class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            int letter = (columnNumber-1)%26;
            ans = char('A'+letter) + ans;
            columnNumber = (columnNumber-1)/26;
        }
        return ans;
    }
};