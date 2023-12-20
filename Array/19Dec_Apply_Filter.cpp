//Brute force O(n*2) space complexity
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Create temp array of size n.
        vector<int> temp(n);
        int prevCorner = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int sum = 0;
                int count = 0;

                // Bottom neighbors
                if (i + 1 < m) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count += 1;
                    }
                    sum += img[i + 1][j];
                    count += 1;
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        count += 1;
                    }
                }

                // Next neighbor
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    count += 1;
                }
                
                // This cell
                sum += img[i][j];
                count += 1;

                // Previous neighbor
                if (j - 1 >= 0) {
                    sum += temp[j - 1];
                    count += 1;
                }

                // Top neighbors
                if (i - 1 >= 0) {
                    // Left-top corner-sharing neighbor.
                    if (j - 1 >=  0) {
                        sum += prevCorner;
                        count += 1;
                    }
                    
                    // Top edge-sharing neighbor.
                    sum += temp[j];
                    count += 1;

                    // Right-top corner-sharing neighbor.
                    if (j + 1 < n) {
                        sum += temp[j + 1];
                        count += 1;
                    }
                }

                // store corner value
                if (i - 1 >= 0) {
                    prevCorner = temp[j];
                }

                // Store current value
                temp[j] = img[i][j];

                // Overwrite with smoothed value.
                img[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return img;
    }
};


//2nd solution O(n) space
class Solution {
public:
    bool isSafe(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m){
            return true;
        }

        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
         int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int dx[9]={-1,-1,-1,0,0,0,1,1,1};
                int dy[9]={-1,0,1,-1,0,1,-1,0,1};
                int sum=0;
                int count=0;
                for(int k=0;k<9;k++){
                    if(isSafe(i+dx[k],j+dy[k],n,m)){
                       sum+=img[i+dx[k]][j+dy[k]];
                       count++;
                    }
                }
                int avg=sum/count;
                ans[i][j]=avg;
            }
        }
        return ans;
    }
};