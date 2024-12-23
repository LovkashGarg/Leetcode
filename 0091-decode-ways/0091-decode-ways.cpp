class Solution {
public:

    int solve(int index,string s, int n,vector<int>&dp){

       if(index>=n){
return 1;
       }
       if(dp[index]!=-1){
        return dp[index];
       }
    
    int a=0,b=0,c=0,d=0,e=0;
        //there can be two ways
         if(s[index]=='1'){
            // two possiblity 
            a=solve(index+1,s,n,dp);
            // and it can be
            if(index+1 <n ){
            b=solve(index+2,s,n,dp);
            }
        }
        else if(s[index]=='2'){
          
          // two possiblity 'B or 'VWXYZ'
          c=solve(index+1,s,n,dp);
          if(index+1<n && s[index+1]<='6'){
          d= solve(index+2,s,n,dp);
          }
        }
        else if(s[index]>='3' && s[index]<='9'){
       e= solve(index+1,s,n,dp);
        }
        else{
            return 0;
        }

        dp[index]=a+b+c+d+e;
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