class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      if(nums.size()==1){
        return nums[0];
      }  
      // check for first and last element 
      if(nums[0]!=nums[1]){
        return nums[0];
      }
      int n=nums.size();
      if(nums[n-1] !=nums[n-2]){
        return nums[n-1];
      }
      int low=0;
      int high=n-1;
      while(low<=high){
        // if there are odd number of element in the right side then the single element is on    right side 
        int mid=(low)+ (high-low)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        // means  element on left is equal // therefore i treat my element part of left side
        else if(nums[mid]==nums[mid-1]){
            // number of element on left = mid+1 
             if((mid-low+1)%2==0){
                // means all the element on left are ok 
                // eliminate left part 
                low=mid+1;
             }
             else{
                high=mid-2;
             } 
        }
        else if(nums[mid]==nums[mid+1]){
            // number of element on right = high-(mid)+1
            if((high-mid+1)%2==0){
                cout<<"Hello"<<endl;
                // means right part is ok 
                high=mid-1;
            }else{
                low=mid+2;
            }
        }
       
      }
      return -1;
    }
};