class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> X;
        for(auto point:points){
            X.push_back(point[0]);
        }
        sort(X.begin(),X.end());
        int maxi=INT_MIN;
        for(int i=0;i<X.size()-1;i++){
            maxi=max(maxi,X[i+1]-X[i]);
        }

        return maxi;
    }
};