class Solution {
public:
    bool solve(vector<int>& stones, int index, int laststep,vector<vector<int>>&dp) {
        // cout << index << laststep << endl;
        if (index == stones.size() - 1) {
            return true;
        }
        if(dp[index][laststep]!=-1){
            // cout<<" Hello"<<endl;
            return dp[index][laststep];
        }

        if (index == 0) {
            // I can go only one step
            // laststep = 1;
            if (stones[1] != 1) {
                return dp[index][laststep]= false;
            }
            return dp[index][laststep]= solve(stones, index + 1, laststep,dp);
        } else {

            // If I am one index  then
            // I can take three steps

            bool step1 = false;
            bool step2 = false;
            bool step3 = false;

            for (int i = index + 1; i < stones.size(); i++) {
                 if(  (step1|| step2|| step3)==true){
                    return dp[index][laststep]= true;
                 }

                if (stones[i] == stones[index] + laststep) {
                    step1 = step1 || solve(stones, i, laststep,dp);
                }

                if (stones[i] == stones[index] + laststep + 1) {

                    step2 = step2 || solve(stones, i, laststep + 1,dp);
                }

                if (stones[i] == stones[index] + laststep - 1) {

                    step3 = step3 ||  solve(stones, i, laststep - 1,dp);
                }
            }

            return dp[index][laststep]= step1 || step2 || step3;
        }
    }
    bool canCross(vector<int>& stones) {

        // say I am on
        int index = 0;
        int k = 1;
        int n=stones.size();
        // long int maxdiff= (stones[n-1]-stones[0]);
        // long  int d= min(maxdiff+1, INT_MAX);
        vector<vector<int>>dp(stones.size()+1, vector<int> (n,-1));
        return solve(stones, index, k,dp);
    }
};