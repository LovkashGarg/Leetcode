class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;  // Base case: No coins needed for amount 0
        if (amount < 0) return INT_MAX;  // Base case: Impossible to reach negative amount
        
        if (dp[amount] != -1){
             return dp[amount]; 
        }
        

        int ans = INT_MAX;
        for (int coin : coins) {
            int sub_res = solve(coins, amount - coin, dp);
            if (sub_res != INT_MAX) {
                ans = min(ans, 1 + sub_res);  
            }
        }
        
        dp[amount] = ans;  // Memoize result
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0; 

        vector<int> dp(amount + 1, -1);  
        int ans = solve(coins, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
