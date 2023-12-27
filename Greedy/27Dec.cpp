// 1578. Minimum Time to Make Rope Colorful
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(i+1<n && colors[i]!=colors[i+1]){
                maxi=max(maxi,neededTime[i]);
                sum+=neededTime[i];
                sum-=maxi;
                maxi=INT_MIN;
            }
            else{
               sum+=neededTime[i];
               maxi=max(maxi,neededTime[i]);
            }
        }

        return sum-maxi;
    }
};