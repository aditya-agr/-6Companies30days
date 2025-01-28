class ThroneInheritance {
public:
    unordered_map<string, vector<string>> mp;
    unordered_set<string> dead;
    string king;

    ThroneInheritance(string kingName) {
        king = kingName;    
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        stack<string> st;
        st.push(king);
        vector<string> res;
        while(!st.empty()){
            string p = st.top();
            st.pop();
            if(dead.count(p)==0)
                res.push_back(p);
            int n = mp[p].size();
            for(int i=n-1; i>=0; i--)
                st.push(mp[p][i]);
        }
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */