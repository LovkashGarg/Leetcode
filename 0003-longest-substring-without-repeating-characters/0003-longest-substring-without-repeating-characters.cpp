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
            int count=0;
            for(int j=i;j<n;j++){
                if(m.find(s[j])==m.end()){
                      m[s[j]]++;
                      count++;
                }
                else{
               cout<<s[j]<<endl;
                 break; 
                }
            }
            cout<<count<<endl;
            finalmax=max(finalmax,count);
        }
        return finalmax;
    }
};