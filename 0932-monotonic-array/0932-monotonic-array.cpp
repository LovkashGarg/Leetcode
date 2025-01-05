class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
     bool first=true;
     bool second=true;
     int n=nums.size();
      for(int i=0;i<n-1;i++){
       if(nums[i] >nums[i+1]){
         first=false;
         break;
       }
      } 
        for(int i=0;i<n-1;i++){
       if(nums[i] <nums[i+1]){
         second=false;
         break;
       }
      } 
      return first || second;

    }
};