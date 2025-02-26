class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        long long ans=0;

        int n= nums.size();

        long long maxsum=INT_MIN;
        long long currsum=0;
        for(int i=0;i<n;i++){
           currsum+=nums[i];
           if(currsum<0){
             currsum=0;
           }
           maxsum= max(maxsum, currsum);
        }
        currsum=0;
       long long minsum=INT_MAX;
         for(int i=0;i<n;i++){
           currsum+=nums[i];
           if(currsum >0){
            currsum=0;
           }
           minsum= min(minsum, currsum);
           minsum= min(minsum, 1ll*nums[i]);
        }

       return max(maxsum,abs(minsum));

    }
};