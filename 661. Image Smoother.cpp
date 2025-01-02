class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                int curr = img[i][j], cnt = 1;
                for(auto d : dir){
                    int ni = i+d[0];
                    int nj = j+d[1];
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        cnt++;
                        curr += img[ni][nj];
                    }
                }
                res[i][j] = curr/cnt;
            }
        }
        return res;
    }
};