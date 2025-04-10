class Solution {
public:

    int solve(int index, vector<int>& stoneValue, int n,vector<int>&dp) {

        if (index >= n) return 0;

        if (dp[index] != INT_MIN) return dp[index];

        int maxDiff = INT_MIN; // max diff set to minimum taking the fact that other person has maximum score  

        int currSum = 0;

        for (int i = index; i<min(index+3, n); i++) {
            currSum += stoneValue[i];
            maxDiff = max(maxDiff, currSum - solve( i + 1, stoneValue, n,dp));
        }

        return dp[index] = maxDiff;

    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n+1,INT_MIN);

        int diff = solve(0, stoneValue, n,dp); // Alice - Bob

        if (diff > 0) return "Alice";
        else if (diff < 0) return "Bob";
        else return "Tie";
    }
};
