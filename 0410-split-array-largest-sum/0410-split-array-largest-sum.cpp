class Solution {
public:
   int countsubarrays(vector<int> & nums,int mid){
    int countsubarrays=1;
    int subarrysum=0;
    for(int i=0;i<nums.size();i++){
       if(subarrysum + nums[i]<=mid){
            subarrysum+=nums[i];
       }
       else{
          countsubarrays++;
          subarrysum=nums[i];
       }
    }
    return countsubarrays;
   }
    int splitArray(vector<int>& nums, int k) {
        
        // minimum value that can be our answer is 
        int maxi=0;
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        long long int  low=maxi;
        long long int high=sum;

        while(low<=high){
            long long int mid=low + (high-low)/2;

            int noofsubarrays=countsubarrays(nums,mid);

            if(noofsubarrays >k){
                low=mid+1;
            }
            else{
                high=mid-1; // means we need to divide the subarray such that no of subarrays approaches to k
            }
        }
        return low;
    }
};