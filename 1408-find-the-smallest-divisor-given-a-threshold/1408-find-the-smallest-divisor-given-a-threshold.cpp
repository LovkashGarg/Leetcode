class Solution {
public:
    int calculateThresholdSum(vector<int> & nums,int threshold, int mid){
        int n=nums.size();
        int thresholdsum=0;
        for(int i=0;i< n;i++){
            thresholdsum+= ceil(double(nums[i])/double(mid));
            if(thresholdsum >threshold){
                return threshold +1;
            }
        }
        return thresholdsum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        // here when maxi  then we get threshold sum = n therefore is minimum 
        int low=1;
        int high=maxi;
        int ans=maxi;
        while(low<=high){
            int mid=(low)+ (high-low)/2;
            int thresholdsum=calculateThresholdSum(nums,threshold,mid);
            if(thresholdsum >threshold){
                low =mid+1; // I want a bigger divisor so that threshold sum reduces 
            }
            else{
                ans=mid;
                high=mid-1;
            } 
        }
        return ans;
    }
};