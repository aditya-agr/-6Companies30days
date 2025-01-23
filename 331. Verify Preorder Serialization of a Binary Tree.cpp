class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> s;
        stringstream ss(preorder);
        string num;
        while(getline(ss, num, ','))
            s.push_back(num);
        int n = s.size();
        int curr = 1;
        for(int i=0; i<n-1; i++){
            if(s[i] != "#")
                curr++;
            else
                curr--;
            if(curr <= 0)
                return false;
        }
        if(s[n-1] == "#")
            curr--;
        return curr == 0;

    }
};