class Solution {
public:
    int countCollisions(string directions) {
        int c = 0;
        int n = directions.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(directions[i] == 'R')
                c++;
            else{
                ans += c;
                c = 0;
            }
        }
        c = 0;
        for(int i=n-1; i>=0; i--){
            if(directions[i] == 'L')
                c++;
            else{
                ans += c;
                c = 0;
            }
        }

        return ans;
    }
};