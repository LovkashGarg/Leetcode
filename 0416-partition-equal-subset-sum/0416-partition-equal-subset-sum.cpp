class Solution {
public:
    bool solve(vector<int>& nums, int n, int index, int target,
               vector<vector<int>>& dp) {
        if (index >= n) {
            return false;
        }
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        bool include = solve(nums, n, index + 1, target - nums[index], dp);
        bool exclude = solve(nums, n, index + 1, target, dp);
        dp[index][target] = include || exclude;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        cout << target << endl;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return solve(nums,n,0,target,dp);
        // return solveTab(nums, sum, n);
        return solvespace(nums,sum,n);
    }
    bool solveTab(vector<int> nums, int total, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(total / 2 + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int index = n - 1; index >= 0; index--) {
            for (int target = 0; target <= total / 2; target++) {
                bool include = 0;
                if (target - nums[index] >= 0) {
                    include = dp[index + 1][target - nums[index]];
                }
                bool exclude = dp[index + 1][target];
                dp[index][target] = include || exclude;
            }
        }
        return dp[0][total / 2];
    }
    bool solvespace(vector<int> nums, int total, int n) {
        int t = total;
        vector<int> curr(t + 1, 0);
        vector<int> next(t + 1, 0);
        // I know that the problem can be solved in a  when target=0 then it is
        // 1

        curr[0] = 1;
        next[0] = 1;
        for (int index = n - 1; index >= 0; index--) {
            for (int target = 0; target <= total / 2; target++) {
                int include = 0;
                if (target - nums[index] >= 0) {
                    include = next[target - nums[index]];
                }

                int exclude = next[target-0];

                curr[target] = include || exclude;
            }
            next=curr;
        }
         return next[t/2];
    }
};