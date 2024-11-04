class Solution {
public:
    string compressedString(string word) {
        int i=0;
        int n=word.size();
        string ans;
        while(i<word.size()){
            // cout<<i<<" "<<word[i]<<endl;
            int j=i;
            int len=0;
            while(j<n && word[i]==word[j] && len<9){
                len++;
                j++;
            }
           ans+=(len+'0');
           ans+=word[i];
            // cout<<"Len"<<len<<endl;
            i=j; 
        }
return ans;
    }
};