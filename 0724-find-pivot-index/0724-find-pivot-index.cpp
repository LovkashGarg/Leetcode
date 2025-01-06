class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n=nums.size();

        vector<int>prefixsum(n,0);
        int sum=nums[0];
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i]= prefixsum[i-1]+ nums[i];
            sum+=nums[i];
        }

        for(int i=0;i<n;i++){
           // here left sum 
           int leftsum= prefixsum[i]-nums[i];
           int rightsum= sum-prefixsum[i];

           if(leftsum== rightsum){
            return i;
           }
        }
        return -1;
    }
};