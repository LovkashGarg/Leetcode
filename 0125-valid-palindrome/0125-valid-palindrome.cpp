class Solution {
public:
    bool isPalindrome(string s) {
      
        string d;
        int n=s.length();
        for(int i=0;i< n;i++){
            if((s[i]>='a' && s[i] <='z' ) || (s[i]>='A' && s[i] <='Z' )  || (s[i]>='0' && s[i] <='9' )){
                if(s[i] >='A' && s[i]<='Z'){
                    d+= int(s[i]-'A')+ 'a';
                }
                else{
                   d+=s[i];
                }
            }
        }
        // s=d;
          int l=0;
        int r=d.length()-1;
        cout<<d<<endl;
        while(l<=r){
            // cout<<s[l]<<" "<<s[r]<<endl;
            if(d[l]!=d[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};