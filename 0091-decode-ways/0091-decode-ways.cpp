class Solution {
public:

    int solve(int index,string s, int n,vector<int>&dp){

       if(index>=n){
return 1;
       }
       if(dp[index]!=-1){
        return dp[index];
       }
    
    int ans=0;
        //there can be two ways
         if(s[index]=='1'){
            // two possiblity 
            ans+=solve(index+1,s,n,dp);
            // and it can be
            if(index+1 <n ){
            ans+=solve(index+2,s,n,dp);
            }
        }
        else if(s[index]=='2'){
          
          // two possiblity 'B or 'VWXYZ'
          ans+=solve(index+1,s,n,dp);
          if(index+1<n && s[index+1]<='6'){
          ans+= solve(index+2,s,n,dp);
          }
        }
        else if(s[index]>='3' && s[index]<='9'){
       ans+= solve(index+1,s,n,dp);
        }
       

        dp[index]=ans;
        return dp[index];
    }
    int numDecodings(string s) {
       
        int n=s.size();
        int index=0;
        vector<int>dp(n+1,-1);
        int ans =solve(index,s,n,dp);
        return ans;
    }
};