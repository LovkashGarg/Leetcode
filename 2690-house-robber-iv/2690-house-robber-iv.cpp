class Solution {
public:
bool canRob(vector<int>& nums, int mid, int k) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
int mini=INT_MAX;
int maxi=INT_MIN;
int n=nums.size();
       for(int i=0;i<n;i++){
           mini=min(mini,nums[i]);
           maxi=max(maxi,nums[i]);
       } 

       int low= mini;
       int high=maxi;
       int ans= maxi;
       while(low<=high){
        int mid= low + ( high-low)/2;
        if(canRob(nums, mid, k)){
            ans=mid;
           high=mid-1;
        }
        else{
            // so that they can select more elements 
            low=mid+1;
        }

       }
       return ans;

    }
};