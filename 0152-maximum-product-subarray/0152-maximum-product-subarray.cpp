class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int n=nums.size();
        int maxans=INT_MIN;
        for(int i=0;i<n;i++){
            if(suffix==0){
                suffix=1;
            }
            if(prefix==0){
                prefix=1;
            }
            prefix=prefix*nums[i];
            suffix=suffix*(nums[n-i-1]);
            maxans=max(maxans,max(prefix,suffix));
        }
        return maxans;
    }
};