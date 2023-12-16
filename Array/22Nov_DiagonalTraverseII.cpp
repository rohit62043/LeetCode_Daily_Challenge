class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int> b){
        if(a.first==b.first){
            return a.second<b.second;
        }

        return a.first<b.first;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
       int n=nums.size();
       vector<pair<int,int>> temp;

       for(int i=0;i<n;i++){
           for(int j=0;j<nums[i].size();j++){
               temp.push_back({i+j,j});
           }
       } 

       sort(temp.begin(),temp.end(),cmp);

       vector<int> ans;

       for(int i=0;i<temp.size();i++){
           int row=temp[i].first-temp[i].second;
           int col=temp[i].second;
           ans.push_back(nums[row][col]);
       }

       return ans;
    }
};