class Solution {
public:
    long long solve(int n,vector<int> & dp){
        if(n<0){
            return INT_MAX;
        }
        else if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        long long mini=INT_MAX;
        for(int i=1;i*i<=n;i++){
          mini=min(mini,1+ solve(n-i*i,dp));
        }


        return dp[n]=mini;

    }
    int numSquares(int n) {
        
        // 
    vector<int>dp(n+1,-1);
    return solve(n,dp);
    }
};