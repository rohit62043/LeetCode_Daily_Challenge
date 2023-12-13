class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> countRow(n,0);
        vector<int> countCol(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                  countRow[i]++;
                  countCol[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                   if(countRow[i]==1 && countCol[j]==1){
                       count++;
                   }
                }
            }
        }

        return count;
    }
};