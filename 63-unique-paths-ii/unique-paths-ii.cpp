class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& maze) {
        int m = maze.size();
        int n = maze[0].size();
         vector<int>prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);

            for(int j=0;j<n;j++){

            if( maze[i][j]==1){
                temp[j]=0;
                continue;
            }
               else if(i==0 && j==0){
                    temp[j]=1;
                continue;
                }
                else{
            int up = 0;
            int left =0;

            if(i>0){
                up = prev[j];
            }

            if(j>0){
                left = temp[j-1];
            }
                temp[j] = up + left;
                }
            }
        prev=temp;
        }
        return prev[n-1];
    }
};