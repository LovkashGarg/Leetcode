class Solution {
public:
    void solve(int n, int i,vector<int>& ans, vector<vector<int>>&finalans,int k){
       
        if(ans.size()==k){
            finalans.push_back(ans);
            return;
        }
        if(i==n+1){
            return ;
        }
         
         // include
         ans.push_back(i);
         solve(n, i+1,ans,finalans,k);
         ans.pop_back();

// exclude
         solve(n,i+1,ans,finalans,k);

    }
    vector<vector<int>> combine(int n, int k) {
        int i=1;
        vector<int>ans;
        vector<vector<int>>finalans;
        solve(n,i,ans,finalans,k);
        return finalans;
    }
};