class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){

          int mid=(low)+ (high-low)/2;
         
          if(nums[mid]==target){
            return true;
          }
          // shrink down my array since they are not equal to target 
          // edge case 3 ,1,2,3,3,3,3 Here mid==3 and low==3 and high==3 

          // we are unable to identify the sorted part 
           if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low=low+1;
                high=high-1;
                continue;
            }
          else if(nums[low]<=nums[mid] ){
              
              if(nums[low]<=target && target<nums[mid] ){
                    high=mid-1;
              }
              else{
                low=mid+1;
              }
          }
          else {
               if(nums[mid]<target && target<=nums[high]){
                 low=mid+1;
               }
               else{
                high=mid-1;
               }
          }
        }
        return false;
    }
};