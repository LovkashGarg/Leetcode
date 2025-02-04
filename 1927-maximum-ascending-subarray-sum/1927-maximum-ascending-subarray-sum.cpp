class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        int maxsum=0;

        while(i<n){
            int sum=nums[i];
            int j=i+1;
            while(j<n && nums[j]>nums[j-1]){
                sum+=nums[j];
                j++;
            }

          i=j;
            maxsum=max(maxsum,sum);
        }
        
        return maxsum;
    }
};