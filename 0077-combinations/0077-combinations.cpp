class Solution {
public:
    void solve(int n, int i,vector<int> ans, vector<vector<int>>&finalans,int k){
       
        if(ans.size()==k){
            finalans.push_back(ans);
            return;
        }
      
         
         
         // include
         for(int j=i;j<n+1;j++){
         ans.push_back(j);
         solve(n, j+1,ans,finalans,k);
         // backtrack
         ans.pop_back(); // this statement ensure backtrack
         } 

    }
    vector<vector<int>> combine(int n, int k) {
        int i=1;
        vector<int>ans;
        vector<vector<int>>finalans;
        solve(n,i,ans,finalans,k);
        return finalans;
    }
};