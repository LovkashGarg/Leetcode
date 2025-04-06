class Solution {
public:
    bool check (string &s ){
         int i=0;
         int j= s.size()-1;
         while(i<=j){
           if(s[i]==s[j]){
            i++;
            j--;
           }
           else{
            return false;
           }
         }

         return true;
    }
   int solve(int i , string & s,vector<int> & dp){
     int n= s.size();
    if(i==s.size()){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];
    }

    int count =INT_MAX;
     string temp;
    for(int k=i ;k<n;k++){
         temp+=s[k];
        // when k == j means no partitioning already palindrome 
         if(check(temp)){
         count = min(count , 1 + solve(k+1,s,dp));
         }
         
    }

    return dp[i]=count;
   }
    int minCut(string s) {
        
        // first I   have to define all the palindrome 
        int n= s.size();
        vector<int>dp(n+1 ,-1);
        return solve(0,s,dp )-1;
    }
};