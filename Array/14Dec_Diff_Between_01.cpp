class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> row(n,vector<int>(2,0));
        vector<vector<int>> col(m,vector<int>(2,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i][1]++;
                    col[j][1]++;
                }
                else{
                    row[i][0]++;
                    col[j][0]++;
                }
            }
        }

        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int tempOnes=row[i][1]+col[j][1];
                int tempZeros=row[i][0]+col[j][0];

                ans[i][j]=tempOnes-tempZeros;
            }
        }

        return ans;
    }
};