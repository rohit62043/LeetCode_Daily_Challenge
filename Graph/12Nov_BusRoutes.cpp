class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
     if(source==target){
        return 0;
     }
     unordered_map<int,vector<int>> mp;
     for(int i=0;i<routes.size();i++){
        for(auto x:routes[i]){
            mp[x].push_back(i);
        }
     }

     int busCount=1;
     queue<int> q;
     vector<int> vis(1000,0);
     for(auto x:mp[source]){
         cout<<x<<endl;
         q.push(x);
         vis[x]=1;
     }
     
     while(!q.empty()){
         int k=q.size();
         while(k--){
             int bus=q.front();
             q.pop();
             for(auto x:routes[bus]){
             if(x==target){
                 return busCount;
             }
             for(auto temp:mp[x]){
                 if(vis[temp]==0){
                     q.push(temp);
                     vis[temp]=1;
                 }
             }
         }
         }

         busCount++;
     }

     return -1;
    }
};