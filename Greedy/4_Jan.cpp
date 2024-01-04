// 2870. Minimum Number of Operations to Make Array Empty
int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }

        int count=0;
        for(auto x:mp){
           int freq=x.second;
           if(freq==1){
               return -1;
           }
           count+=ceil((double)freq/3);
        }
        return count;
}