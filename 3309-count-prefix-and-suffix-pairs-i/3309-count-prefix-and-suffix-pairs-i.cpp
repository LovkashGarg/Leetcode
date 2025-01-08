class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        // time complexicity is O(n*n * (min(len(i) ,len(j))))
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
         for(int j=i+1;j<n;j++){
           
           int l=0;
           while(l<words[i].size()  && l< words[j].size()){

            if(words[i][l]!=words[j][l]){
                break;
            }
            l++;
           }
           
           int m=words[i].size()-1;
           int c=words[j].size()-1;
           int len=0;
           while(len<words[i].size() && len< words[j].size() ){

            if(words[i][m]!=words[j][c]){
                break;
            }
            m--;
            c--;
            len++;
           }


           if(l== words[i].size() && len== words[i].size()){
            count++;
           }


         }
        }
        return count;
    }
};