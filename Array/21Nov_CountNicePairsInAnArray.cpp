class Solution {
public:
    long long m=1e9+7;
    int rev(int n){
        int ans=0;
        while(n){
            int x=n%10;
            n=n/10;
            ans=10*ans+x;
        }

        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            int x=nums[i]-rev(nums[i]);
            arr.push_back(x);
        }
       unordered_map<int, int> count;
       for(int i=0;i<arr.size();i++){
          count[arr[i]]++;
       } 
       long long result = 0;

       for(auto x:count){
           long long d=x.second;
           long long temp = (d *(d-1))/2;
            result+=temp;
            result = result % m;
       }

       return result%m;
    }
};