// 2610. Convert an Array Into a 2D Array With Conditions
//method1
 vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        while(!mp.empty()){
            vector<int> temp;
            unordered_map<int,int> f;
            for(auto x:mp){
                temp.push_back(x.first);
                if(x.second-1!=0){
                    f[x.first]=x.second-1;
                }
            }
            mp=f;
            ans.push_back(temp);
        }

        return ans;
    }

    //method 2
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> freq;
        
        for(auto num:nums){
            if(freq[num]==ans.size()){
                ans.push_back({});
            }
            ans[freq[num]].push_back(num);
            freq[num]++;
        }

        return ans;
    }