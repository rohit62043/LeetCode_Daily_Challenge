<!-- Solution 1-->Brute Force--> T.C=O(n**2) -->
int maxScore(string s) {
        int ans=INT_MIN;
        int n=s.size();
       
        
        for(int i=0;i<n-1;i++){
            int count0=0;
            for(int st=0;st<=i;st++){
               if(s[st]=='0'){
                   count0++;
               }
            }
            int count1=0;
            for(int e=i+1;e<n;e++){
               if(s[e]=='1'){
                count1++;
               }
            }

            ans=max(ans,(count0+count1));
        }

        return ans;
    }

<!-- Solution 2-->Optimise Solution(Two parse)-->T.C=O(n) -->
int maxScore(string s) {
        int ans=INT_MIN;
        int n=s.size();
       int total1=0;
       for(auto x:s){
           if(x=='1'){
               total1++;
           }
       }
        int count0=0;
        int count1=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                count0++;
            }
            else{
                count1++;
            }
            int Fcount1=total1-count1;
            ans=max(ans,(count0+Fcount1));
        }

        return ans;
    }
<!-- Solution 3-->Optimal Solution(One Parse)-->T.C=O(n) -->
int maxScore(string s) {
        int ans=INT_MIN;
        int n=s.size();
        int count0=0;
        int count1=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                count0++;
            }
            else{
                count1++;
            }
            ans=max(ans,(count0-count1));
        }
        if(s[n-1]=='1'){
            count1++;
        }
        return ans+count1;
    }