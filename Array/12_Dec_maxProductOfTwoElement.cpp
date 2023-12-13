class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Using sort function
        // int n=nums.size()-1;
        // sort(nums.begin(),nums.end());

        // return (nums[n]-1)*(nums[n-1]-1);

        int prev=-1;
        int curr=-1;

        for(auto x:nums){
            if(curr==-1){
                curr=x;
            }
            else{
                if(curr<=x){
                    prev=curr;
                    curr=x;
                }
                else if(prev<=x){
                    prev=x;
                }
            }
        }

        return (prev-1)*(curr-1);
    }
};