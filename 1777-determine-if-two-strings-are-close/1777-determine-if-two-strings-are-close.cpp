class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(m!=n){
            return false;
        }
      vector<int>v1(26,0);
      vector<int>v2(26,0);
        for(int i=0;i<m;i++){
           v1[word1[i]-'a']++;
        }
      
         for(int i=0;i<n;i++){
           v2[word2[i]-'a']++;
        }

// this would ensure we swap only those character which are present in both at least once 
        for(int i=0;i<26;i++){
            if(v1[i] >0 && v2[i] ==0){
                return false;
            }
            else if(v1[i]==0 && v2[i]>0){
              return false;
            }
        }


  sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};