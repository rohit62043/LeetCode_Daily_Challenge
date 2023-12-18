class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int w=nums[0];
        int x=nums[1];
        int y=nums[n-1];
        int z=nums[n];

        return (y*z)-(w*x);
    }
};