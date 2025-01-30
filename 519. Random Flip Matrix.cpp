class Solution {
public:
    unordered_set<int> st;
    int N, M;
    Solution(int m, int n) {
        N = m;
        M = n;
    }
    
    vector<int> flip() {
        int num = rand()%(N*M);
        while(st.count(num))
            num = (num+1)%(N*M);
        int i=num/M, j=num%M;
        st.insert(num);
        return {i, j};
    }
    
    void reset() {
        st = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */