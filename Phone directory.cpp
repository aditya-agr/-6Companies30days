class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int m = s.length();
        string curr="";
        vector<vector<string>> res(m);
        for(int i=0; i<m; i++){
            curr += s[i];
            unordered_set<string> st;
            for(int j=0; j<n; j++){
                string con = contact[j];
                int csz = con.length();
                int x=0;
                while(x<i+1 && x<csz){
                    if(s[x] != con[x])
                        break;
                    x++;
                }
                if(x==i+1)
                    st.insert(con);
            }
            if(st.empty())
                st.insert("0");
            vector<string> tmp(st.begin(), st.end());
            res[i] = tmp;
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};