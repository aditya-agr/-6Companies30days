class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string res = "";
        int n = S.size();
        stack<string> st;
        int c = 1;
        for(int i=0; i<n; i++){
            st.push(to_string(c));
            c++;
            if(S[i]=='I'){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
            }
        }
        st.push(to_string(c));
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};