class Solution {
public:
vector<vector<int>>ans;
    void solve(int index,vector<int>& candidates, int target,int n,vector<int>&output ){

       if (target == 0) {
            ans.push_back(output);
            return;
        }


        for(int i=index;i<n;i++){

            if(target- candidates[i]>=0){
            output.push_back(candidates[i]);
            solve(i, candidates, target- candidates[i],n,output);
            output.pop_back();
            }


            // solve(i, candidates, target,output);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            ans.clear(); // Clear results for multiple test cases
        vector<int>output;
        int n=candidates.size();
        int index=0;
       solve(index, candidates, target,n,output);
       return ans;

    }
};