class Solution {
public:
    int solve(vector<int>& jD, int d,int index){
        if(d==1){
            int maxDif=INT_MIN;
            for(int i=index;i<jD.size();i++){
                maxDif=max(maxDif,jD[i]);
            }
            return maxDif;
        }


        int finalAns=INT_MAX;
        int maxi=jD[index];
        for(int i=index;i<=jD.size()-d;i++){
            maxi=max(maxi,jD[i]);
            int ans=maxi+solve(jD,d-1,i+1);
            finalAns=min(finalAns,ans);
        }

        return finalAns;
    }
    int solveMemo(vector<int>& jD, int d,int index,vector<vector<int>>& dp){
        if(d==1){
            int maxDif=INT_MIN;
            for(int i=index;i<jD.size();i++){
                maxDif=max(maxDif,jD[i]);
            }
            return maxDif;
        }
        if(dp[index][d]!=-1){
            return dp[index][d];
        }

        int finalAns=INT_MAX;
        int maxi=jD[index];
        for(int i=index;i<=jD.size()-d;i++){
            maxi=max(maxi,jD[i]);
            int ans=maxi+solveMemo(jD,d-1,i+1,dp);
            finalAns=min(finalAns,ans);
        }

        return dp[index][d]=finalAns;
    }
    int tabular(vector<int>& jD, int d){
         int n=jD.size();
         vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
         for(int i=0;i<n;i++){
            dp[i][1]=*max_element(begin(jD) + i, end(jD));
         }

         for(int day=2;day<=d;day++){
            for(int index=n-day;index>=0;index--){
                int finalAns=INT_MAX;
                int maxi=INT_MIN;
                for(int i=index;i<=n-day;i++){
                    maxi=max(maxi,jD[i]);
                    int ans=maxi+dp[i+1][day-1];
                    finalAns=min(finalAns,ans);
                }
                dp[index][day]=finalAns;
            }
         }

         return dp[0][d];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d){
            return -1;
        }

       // return solve(jobDifficulty,d,0);
       vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
       //return solveMemo(jobDifficulty,d,0,dp);
       return tabular(jobDifficulty,d);
    }
};