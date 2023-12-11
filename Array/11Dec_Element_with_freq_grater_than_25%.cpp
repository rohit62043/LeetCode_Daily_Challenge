class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // ***USING HASHMAP****
        // int n=arr.size();
        // int freq=(n*25)/100;

        // unordered_map<int,int> mp;
        // for(auto x:arr){
        //     mp[x]++;
        // }

        // for(auto x: mp){
        //     if(x.second>freq){
        //         return x.first;
        //     }
        // }
        
        // return -1;

        // ***Check the Element N/4 Ahead**

        // int n=arr.size();
        // int quater=n/4;

        // for(int i=0;i<n-quater;i++){
        //     if(arr[i]==arr[i+quater]){
        //         return arr[i];
        //     }
        // }

        // return -1;

        // USING BS
        int n=arr.size();
        vector<int> candidates ={ arr[n/4],arr[n/2],arr[3*n/4]};

        for(auto x:candidates){
            int leftOcc=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            int rightOcc=upper_bound(arr.begin(),arr.end(),x)-arr.begin()-1;
            int frequency=rightOcc-leftOcc+1;
            if(frequency>(n/4)){
                return x;
            }
        }

        return -1;
    }
};