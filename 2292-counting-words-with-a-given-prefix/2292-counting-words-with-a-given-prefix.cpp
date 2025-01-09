class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int count=0;
        for(int i=0;i<words.size();i++){
            int l=0;
            while(l<words[i].size() && l<n){
               if(words[i][l]!= pref[l]){
                break;
               }
               l++;
            }

            if(l==n){
                count++;
            }
        }
        return count;
    }
};