class Solution {
public:
    int solve(int idx, vector<vector<int>> &spm){
        int cntN=0, cntE=0, mx=0;
        int n = spm.size();
        for(int i=0; i<n; i++){
            if(((idx>>i)&1) == 0) continue;
            cntN++;
            for(int j=i+1; j<n; j++){
                if(((idx>>j)&1) == 0) continue;
                if(spm[i][j] == 1)
                    cntE++;
                mx = max(mx, spm[i][j]);
            }
        }
        if(cntN == cntE+1)
            return mx;
        return -1;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> spm(n, vector<int>(n, 20));
        for(auto e : edges){
            spm[e[0]-1][e[1]-1] = 1;
            spm[e[1]-1][e[0]-1] = 1;
        }

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    spm[i][j] = spm[j][i] = min({spm[i][j], spm[j][i], spm[i][k]+spm[k][j]});       
        
        vector<int> res(n-1);
        for(int i=0; i<(1<<n); i++){
            int dis = solve(i, spm);
            if(dis>0)
                res[dis-1]++;
        }
        return res;
    }
};