class Solution {
public:
    int partitionString(string s) {
        
        int l=0;
         vector<int>v(26,-1);
         int n=s.size();
         int count=0;
         for(int i=0;i<n;i++){
            if(v[s[i]-'a'] >=l){
                count++;
                l=i;
            }
            v[s[i]-'a']=i;
         }

         // since we donot count the last partiion 
         return count+1;
    }
};