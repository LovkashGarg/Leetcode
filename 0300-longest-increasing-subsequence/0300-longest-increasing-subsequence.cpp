class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        // here base case 
        // dp[prev][n]=0; // already covered 
        vector<int>current(n+1,0);
        vector<int>next(n+1,0);

        for(int curr=n-1;curr>=0;curr--){
             for(int prev=curr-1;prev>=-1;prev--){
                
                 int exclude= next[prev+1];
                 int include=0;

                 if(prev==-1 || nums[prev] < nums[curr]){

                    include= 1 + next[curr+1];

                 }

                 current[prev+1]= max(include, exclude); 
             }
             next=current;
        }

        return next[0];
    }
};