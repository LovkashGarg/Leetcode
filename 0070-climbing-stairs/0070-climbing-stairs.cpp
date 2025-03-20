class Solution {
public:
    int climbStairs(int n) {

      int prev2=1;
      if(n==1){
        return prev2;
      }
      int prev1=2;
int ans;
      for(int i=3;i<=n;i++){
        ans= prev1 + prev2;
        prev2=prev1;
        prev1=ans;
      }
      return prev1;

     
    }
};