class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    unordered_map<char,int> m;
    int n=s.length();
    if(n<=1){
        return n;
    }
    for(int i=0;i<n;i++){
        m[s[i]]=-1;
    }
    int start=-1;
    int i=0;
    int maxlen=1;
    while(i<n){
        // means not first time 
       if(m[s[i]]>start){
         start=m[s[i]];
       }
        m[s[i]]=i;
      maxlen=max(maxlen,i-start);
        i++;
     cout<<maxlen<<endl;
      }
    return maxlen;
    }
};