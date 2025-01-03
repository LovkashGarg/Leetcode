class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        // one case when all are one 
        bool flag=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                flag=false;
                break;
            }
        }

        if(flag==true){
            return n-1;
        }


        // time complexicity is O(2*n)
        for(int i=0;i<n;i++){
            // find ones on left ans right
            if(nums[i]!=1){
               int j=i-1;
                while(j>=0 && nums[j]==1){
                    j--;
                }

                int left= i-j-1;
                j=i+1;

                while(j<n && nums[j]==1){
                j++;
                }

                int right=j-i-1;
                ans=max(ans,left+right);

            }
        }
        return ans;
    }
};