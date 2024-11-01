class Solution {
public:
    string makeFancyString(string s) {
        int i=0;
string ans;
        while(i<s.length()){
            // cout<<s[i]<<endl;
            int count=1;
            char d=s[i];
            ans+=d;
           while(i+1<s.length() && s[i]==s[i+1]){
            count++;
            i++;
           }
            
           if(count >=2){
             ans+=d;
           }
           i++;
        }
        return ans;
    }
};