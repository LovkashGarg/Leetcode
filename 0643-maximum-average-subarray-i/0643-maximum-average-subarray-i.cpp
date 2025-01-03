class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         double sum=0;
         int n=nums.size();
        for(int i=0;i<k-1;i++){
sum+=nums[i];
        }
        double ans=INT_MIN;
        for(int i=k-1;i<n;i++){
            sum+=nums[i];
          ans=max(ans, sum/k);
          sum-=nums[i-(k-1)];
        }
        return ans;
    }
};