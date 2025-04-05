class Solution {
public:
    int solve(int left , int right , vector<int>& cuts ,vector<vector<int>>&dp ){

        if(left > right){
            return 0;
        }

        if(dp[left][right]!=-1){
            return dp[left][right];
        }

        int mini= INT_MAX;
        for(int i=left ;i<= right ;i++){
         int cost = (cuts[right+1] - cuts[left-1] ) + solve(left , i-1,cuts,dp) + solve(i+1, right,cuts,dp);
         mini=min(mini, cost);
        }

return dp[left][right]=mini;

    }

    int minCost(int n, vector<int>& cuts) {
        
        int m= cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(m+1, vector<int>(m+1,-1));

        return solve(1,m,cuts,dp);

    }
};