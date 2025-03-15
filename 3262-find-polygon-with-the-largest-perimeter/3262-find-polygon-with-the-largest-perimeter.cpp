class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        // we know it is a polygon if its smaller parts are polygon as well 
        long long prefixsum=nums[0] + nums[1];
        long long ans=-1;
        int n= nums.size();

        for(int i=2;i<n;i++){
           if(prefixsum > nums[i]){
            ans=max(ans,prefixsum+ nums[i]);
           }
           prefixsum+=nums[i];
        }

        return ans;
    }
};