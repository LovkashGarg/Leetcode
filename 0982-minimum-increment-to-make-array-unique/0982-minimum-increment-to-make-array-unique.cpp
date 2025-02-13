class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
      int count=0;
      int n=nums.size();
      sort(nums.begin(),nums.end());
      for(int i=1;i<n;i++){
        // here if it already exist 
        if(nums[i] <= nums[i-1]){
         int last=nums[i];
          nums[i]=nums[i-1]+1;
         count+= (nums[i-1]+1- last);
        }
        
      } 
      return count;
    }
};