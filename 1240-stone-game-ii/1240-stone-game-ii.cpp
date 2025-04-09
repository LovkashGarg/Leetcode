class Solution {
public:
 int solve(int index ,int m ,int turn ,  int n , vector<int>&piles ,vector<vector<vector<int>>> &dp){
    if(index==n){
        return 0;
    }
    if(dp[index][m][turn]!=-1){
        return dp[index][m][turn];
    }
    // means we can collect 
    if(turn ==0){
    int currsum=0;
    int maxsum=INT_MIN;
      for(int i = index ;i<(min(index + 2*m, n));i++){
           currsum+=piles[i];
           maxsum = max(maxsum , currsum + solve(i+1,max(m, i - index + 1),1,n,piles,dp ));
      }
      return dp[index][m][turn]=maxsum;
    }
    else{

        int minsum = INT_MAX;
            for (int i = index; i < min(index + 2 * m, n); i++) {
                minsum = min(minsum, solve(i + 1, max(m, i - index + 1), 0, n, piles, dp));
            }
            return dp[index][m][turn] = minsum;

     }

     
 }
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>> (2*n+1, vector<int>(2,-1)));
     return solve(0,1,0,n,piles,dp) ;  

    }
};