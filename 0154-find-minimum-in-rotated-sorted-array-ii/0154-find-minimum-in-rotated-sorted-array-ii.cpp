class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low)+ (high-low)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                mini=min(mini,nums[mid]);
                low=low+1;
                high=high-1;
                continue;
            }
           if(nums[mid]<=nums[high]){
             mini=min(mini,nums[mid]);
             high=mid-1;
           }
           else{
            // left part sorted 
             mini=min(mini,nums[low]);
             low=mid+1;
           }
        }
        return mini;
    }
};