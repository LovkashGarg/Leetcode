class Solution {
public:
int ans=0;
void solve(int n, vector<int> &exp,vector<int>&nums,int target,int index,int sum){

    if(index==n){
       
        if(sum==target){
            ans++;
        }
            return;
    }

   exp[index]=-1;
    solve(n,exp,nums,target,index+1,sum + nums[index]*exp[index]);
    exp[index]=1;
    solve(n,exp,nums,target,index+1,sum + nums[index]*exp[index]);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        
      // here two operators psossible for each 
      int n=nums.size();
      vector<int>exp(n,1);
      int index=0;
      int sum=0;
      solve(n,exp,nums,target,index,sum);
    return ans;


    }
};