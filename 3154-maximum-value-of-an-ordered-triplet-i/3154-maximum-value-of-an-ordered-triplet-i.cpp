class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        
        long long maxi=0;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    maxi=max(maxi,1ll*( nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return maxi;
    }
};