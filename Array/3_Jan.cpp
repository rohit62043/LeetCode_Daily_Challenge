// 2125. Number of Laser Beams in a Bank
 int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();

        int curr=0;
        int prev=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
              if(bank[i][j]=='1'){
                  cnt++;
              }
            }
            curr=cnt;
            ans+=(curr*prev);
            if(cnt!=0){
                prev=curr;
            }
        }

        return ans;
    }