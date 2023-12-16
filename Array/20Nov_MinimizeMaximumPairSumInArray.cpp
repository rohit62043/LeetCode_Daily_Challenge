class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=nums[i++]+nums[j--];
            maxi=max(maxi,sum);
        }

        return maxi;
    }
};