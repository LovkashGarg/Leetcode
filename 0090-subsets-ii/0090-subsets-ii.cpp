class Solution {
public:
    void solve( vector<int>& nums,vector<vector<int>> & ans, int index, int n, vector<int> output){

        if(index==n){
            if(find(ans.begin(),ans.end(), output)==ans.end())
            ans.push_back(output);
            return;
        }

        // exclude
        solve(nums, ans, index+1, n, output);
        // include
        output.push_back(nums[index]);
        solve(nums, ans, index+1, n,output);
        // output.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>output;
        solve(nums,ans,0, n, output);
        return ans;
    }
};