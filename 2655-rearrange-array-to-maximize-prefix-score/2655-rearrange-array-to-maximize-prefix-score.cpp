class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        long long int pre=0;
        int count=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            if(pre>0){
                count++;
            }
        }
        return count;
    }
};