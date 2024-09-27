class Solution {
public: 
     void solve(vector<vector<int>>&ans, vector<int> & candidates, int target, int index, vector<int> sub,int n){
          // Base case: found a valid combination
        if (target == 0) {
            ans.push_back(sub);
            return;
        }

// not found a valid one 
          if(index==n){
            return ;
          }


          // exclude

          // include
          if(candidates[index]<=target){
            sub.push_back(candidates[index]);
            solve(ans, candidates, target-candidates[index],index+1, sub, n);
            sub.pop_back();
          }

           // Skip duplicates
          while (index + 1 < n && candidates[index] == candidates[index + 1]) {
            index++;
          }
          solve(ans,candidates, target, index+1, sub, n);
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(),candidates.end());
        long long int sum=0;
        for(int i=0;i< n;i++){
       sum+=candidates[i];
        }
        vector<vector<int>>ans;
        if(sum <target){
            return ans;
        }
        vector<int> sub;
        solve(ans,candidates,target,0,sub,n);
        return ans;
    }
};