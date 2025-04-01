class Solution {
public:
    long long solve(int index,vector<long long >&dp ,vector<vector<int>>& questions,int n){
        if(index>=n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }

        // include 
        long long include= questions[index][0] + solve(index+questions[index][1]+1,dp,questions,n );
        long long exclude =  solve(index+1,dp,questions,n );
        return dp[index]= max(include , exclude);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
       vector<long long >dp(n,-1);
        return solve(0,dp,questions,n);
    }
};