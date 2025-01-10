class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 2)
                    q.push({i, j});
        
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int res = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [x, y] = q.front();
                cout<<x<<y<<" ";
                q.pop();
                for(int k=0; k<4; k++){
                    int nx = x+dir[k][0];
                    int ny = y+dir[k][1];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            res++;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) 
                if(grid[i][j]==1)
                    return -1;
        return res == -1 ? 0 : res;
    }
};