//*******Brute Force Solution***********
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            bool good = true;
            
            for (int j = 0; j < paths.size(); j++) {
                if (paths[j][0] == candidate) {
                    good = false;
                    break;
                }
            }

            if (good) {
                return candidate;
            }
        }
        
        return "";
    }
};

//******Optimized using Hash Map********
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> mp;
        for(auto x:paths){
            mp[x[0]]=x[1];
        }

        for(auto x:mp){
            if(mp.find(x.second)==mp.end()){
                return x.second;
            }
        }

        return "";
    }
};