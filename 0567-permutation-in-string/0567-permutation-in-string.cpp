class Solution {
public:
    bool checkequal(vector<int> & m1,vector<int>& m2){
        for(int i=0;i<26;i++){
            if(m1[i]!=m2[i]){
           return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
       vector<int>m1(26,0);
       vector<int>m2(26,0);
       if(s1.length()>s2.length()){
        return false;
       }
       for(int i=0;i<s1.length();i++){
        m1[s1[i]-'a']++;
       }
       for(int i=0;i<s1.length();i++){
        m2[s2[i]-'a']++;
       } 
       
       if(m1==m2){
        return true;
       }
       for(int j=s1.length();j<s2.length();j++){
          m2[s2[j-s1.length()]-'a']--; // removing the element from window 
          m2[s2[j]-'a']++;
          if(checkequal(m1,m2)){
            return true;
          }
       }
       return false;

    }
};