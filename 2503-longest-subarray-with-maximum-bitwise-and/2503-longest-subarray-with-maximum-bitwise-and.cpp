class Solution {
public:
    int longestSubarray(vector<int>& nums) {
          // Here we choosed the 
        // since the bitwise array of two number is less than the maximum of two numbers

        // Here for array [1,2,3,3,2,2] the max is 3 now find the longest subarray from that 
        int n=nums.size();
        int maxele=0;
        for(int i=0;i<n;i++){
            if(maxele <nums[i]){
                 maxele=nums[i];
            }
        }

        // now check how many times maxelement occurs together 

        int i=0;
        int ans=1;
        while(i<n){
            int len=0;
            while(i<n && nums[i]==maxele){
                len++;
                i++;
            }
            i++;
            ans=max(ans,len);
        }
        return ans;
    }
};