class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int> s(nums[0].begin(), nums[0].end());
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            unordered_set<int>temp;
            for(int j=0;j< nums[i].size();j++){
                if(s.find(nums[i][j]) !=s.end()){
                  temp.insert(nums[i][j]);
                }
            }
            s=temp;
        }
        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};