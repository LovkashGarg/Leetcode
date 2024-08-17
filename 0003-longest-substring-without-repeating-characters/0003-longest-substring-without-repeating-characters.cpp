class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0){
            return 0;
        }
        int finalmax=1;
        for(int i=0;i<n;i++){
            map<char,int>m;
            int j=i;
            for( ;j<n;j++){
                if(m[s[j]]==1){
                      break; 
                }
                else{
                  m[s[j]]++;
                }
            }
            finalmax=max(finalmax,j-i);
        }
        return finalmax;
    }
};