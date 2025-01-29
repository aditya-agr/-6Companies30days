class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
        for(string &s : startWords){
            sort(s.begin(), s.end());
            st.insert(s);
        }
        int count = 0;
        for(string &t : targetWords){
            int n = t.length();
            sort(t.begin(), t.end());
            for(int i=0; i<n; i++){
                string curr = "";
                for(int j=0; j<n; j++)
                    if(i!=j) curr += t[j];
                if(st.find(curr) != st.end()){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};