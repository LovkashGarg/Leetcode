class Solution {
public:
     int solve(int start ,int end , vector<int>& piles , int turn,vector<vector<vector<int>>>&dp){
        if(start >end){
            return 0;
        }
        if(dp[start][end][turn]!=-1){
            return dp[start][end][turn];
        }
        if(turn==0){
          int maxpoints=INT_MIN;
          maxpoints = max(maxpoints , piles[start] + solve(start +1 , end , piles , 1,dp));
          maxpoints = max(maxpoints , piles[end] + solve(start  , end-1 , piles , 1,dp));
          return dp[start][end][turn]= maxpoints;
        }
        else{
          int minpoints=INT_MIN;
          minpoints = max(minpoints , solve(start +1 , end , piles , 0,dp));
          minpoints = max(minpoints , solve(start  , end-1 , piles , 0,dp));
          return dp[start][end][turn]=minpoints;
        }
        
     }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>> (n,vector<int>(2,-1)));
        int maxi= solve(0,n-1,piles,0,dp);
        int total= 0;
       
        for(int i=0;i<n;i++){
            total+= piles[i];
        }

        if(maxi > total/2 ){
            return true;
        }
        else{
            return false;
        }
    }
};