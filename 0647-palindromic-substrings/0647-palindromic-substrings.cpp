class Solution {
public:
     void expandfromcenter(string s, int left,int right,int & count){
    while(left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
        count++;
    }
     
    }
    int countSubstrings(string s) {
        int count=0;
         if(s.size()<=1){
            return 1;
        }
          for(int i=0;i<s.length();i++){
            expandfromcenter(s,i,i,count);
            expandfromcenter(s,i,i+1,count);
          }
        return count;
    }
};