class Solution {
public:
int solve(int index,int last, vector<int> & nums,vector<int>&dp){
    if(index==last){

      return nums[index];
    }

    if(index<last){
return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }

    int include=nums[index];
    if(index-2>=last){
        include+=solve(index-2,last,nums,dp);
    }
    int exclude=0 + solve(index-1,last,nums,dp);
    return dp[index]=max(include,exclude);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        int index=n-1;
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return  max(nums[0],nums[1]);
        }

        vector<int>dp1(n,-1);
        int first=solve(index,1,nums,dp1);
          vector<int>dp2(n,-1);
        int second=solve(index-1,0,nums,dp2);
        // cout<<second<<endl;
        return max(first,second);
    }
};