class Solution {
public:
    string expandfromcenter(string s, int left,int right){
    while(left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
    }
     return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        string res;
        string maxs;
        if(s.size()<=1){
            return s;
        }
        maxs+=s[0];
        for(int i=0;i<s.length()-1;i++){
            string odd=expandfromcenter(s,i,i);
            string even=expandfromcenter(s,i,i+1);

            if(maxs.length() <odd.length()){
                maxs=odd;
            }
            if(maxs.length()<even.length()){
                maxs=even;
            }
        }
        return maxs;
    }
};