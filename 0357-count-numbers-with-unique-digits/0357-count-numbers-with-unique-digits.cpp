class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
      vector<int>dp(10,0);
      dp[0]=1;
      dp[1]=10;
      dp[2]=91;
      int product= 9 *9;
      int start=8;
      for(int i=3;i<=n;i++){
        dp[i]=  dp[i-1] +( product*start);
        product= product*start;
        start=start-1;
      }

       return dp[n];
}

};