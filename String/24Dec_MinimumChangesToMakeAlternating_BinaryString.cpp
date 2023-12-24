// 1758. Minimum Changes To Make Alternating Binary String
class Solution {
public:

    <!-- T.C=O(N)   S.C=O(N) -->
    int minOperations(string s) {
        int n=s.length();
        string s1="";
        string s2="";
        int count=0;

        int flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                s1+='0';
                s2+='1';
                flag=false;
            }else{
                s2+='0';
                s1+='1';
                flag=true;
            }
        }

        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]){
                count1++;
            }
            else if(s[i]!=s2[i]){
                count2++;
            }
        }

        count=min(count1,count2);
        return count;
    }

    <!-- T.C=O(N)   S.C=O(1) -->
    int minOperations(string s) {
        int n=s.length();
        int flag=true;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(flag){
                if(s[i]=='0'){
                    count2++;
                }
                else{
                    count1++;
                }
                flag=false;
            }else{
               if(s[i]=='0'){
                   count1++;
               }
               else{
                   count2++;
               }
                flag=true;
            }
        }

        return min(count1,count2);
    }
};