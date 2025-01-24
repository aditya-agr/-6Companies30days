class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> spm(n, vector<int>(n, 1e4+1));
        for(auto &e : edges){
            spm[e[0]][e[1]] = e[2];
            spm[e[1]][e[0]] = e[2];
        }

        for(int i=0; i<n; i++){
            for(int x=0; x<n; x++)
                for(int y=0; y<n; y++)
                    spm[x][y] = min(spm[x][y], spm[x][i]+spm[i][y]);
        }

        int res=-1, mn=INT_MAX;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++)
                if(i!=j && spm[i][j] <= distanceThreshold)
                    cnt++;
            if(cnt<=mn){
                mn = cnt;
                res = i;
            }
        }
        return res;
    }
};