class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      if(nums.size()==1){
        return nums[0];
      }  
      int n=nums.size();
      // check for first and last element 
      if(nums[0]!=nums[1]){
        return nums[0];
      }
      if(nums[n-1] !=nums[n-2]){
        return nums[n-1];
      }
      int low=1;
      int high=n-2;
      while(low<=high){
        // if there are odd number of element in the right side then the single element is on    right side 
        int mid=(low)+ (high-low)/2;
        
        if((nums[mid]!=nums[mid-1]) && (nums[mid]!=nums[mid+1])){
            return nums[mid];
        }
        // means  element on left is equal // therefore i treat my element part of left side
         // means I am on odd index  and my left index is even and equal then 
         // then we have to go on right side and eliminate left half 
     
     // matlab iska ye hi hai ki no of element on left side of the equal element are if even then we are gone element this side 
        else if(((mid %2==1) && nums[mid]==nums[mid-1]) || ((mid %2==0) && (nums[mid]==nums[mid+1]))){
        low=mid+1;
         }
         else{
            high=mid-1; // eliminate right half
         }
      
      }
      return -1;
    }
};