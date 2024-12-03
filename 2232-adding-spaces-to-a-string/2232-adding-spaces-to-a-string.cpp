class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int i=0;
        int j=0;
        int n=s.size();
        int m=spaces.size();
        string ans;
        while(i<n){
            if(j< spaces.size() && spaces[j]==i){
                ans+=" ";
                j++;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};