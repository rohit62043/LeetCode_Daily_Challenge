class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // if(s==t){
        //     return true;
        // }
        // return false;

       int freqTable[256]={0};

       for(auto x:s){
           freqTable[x]++;
       } 

       for(auto x:t){
           freqTable[x]--;
       }

       for(auto x:freqTable){
           if(x!=0){
               return false;
           }
       }
       return true;
    }
};