class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mini=INT_MAX;
        while(low<=high){
        int mid=(low)+ (high-low)/2;
          
          // means the minimum is on right side 
          // since left side is sorted therefore 
         if(nums[mid]>nums[high]){
            low=mid+1;
         }
         else {
            high=mid-1;
         }
         mini=min(mini,nums[mid]);
        }
        return mini;
    }
};