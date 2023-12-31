// 1624. Largest Substring Between Two Equal Characters
int maxLengthBetweenEqualCharacters(string s) {
        int maxi=-1;
        int n=s.length();
        int i=0;
        int j=n-1;
        while(j>i){
            while(j>i && s[i]!=s[j]){
                j--;
            }
            maxi=max(maxi,j-i-1);
            i++;
            j=n-1;
        }

        return maxi;
    }