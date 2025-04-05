class Solution {
public:
   int solve(int start, int end, vector<int>& cuts, int left, int right, vector<vector<int>>& dp) {
    if (left > right) return 0;

    if (dp[left][right] != -1) return dp[left][right];

    int cost = INT_MAX;

    for (int i = left; i <= right; ++i) {
        int curr_cost = end - start + solve(start, cuts[i], cuts, left, i - 1, dp) + solve(cuts[i], end, cuts, i + 1, right, dp);
        cost = min(cost, curr_cost);
    }

    return dp[left][right] = cost;
}

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    return solve(0, n, cuts, 0, m - 1, dp);
}
};