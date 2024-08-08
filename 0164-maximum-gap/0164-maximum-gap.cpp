class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // base case
        if(nums.size()==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n-1;i++){
          maxi=max(maxi,nums[i+1]-nums[i]);
        }
        return maxi;
    }
};