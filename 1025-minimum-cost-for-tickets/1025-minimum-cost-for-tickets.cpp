class Solution {
public:
   int solve(int index, vector<int>& days, vector<int>& costs,int n,vector<int> &dp){
     if(index==n){
        return 0;
     }
    if(dp[index]!=-1){
        // cout<<" Hel"<<endl;
        return dp[index];
    }
     // I have to see after  buying ticket how much far I go 
     // buying one day pass 
     int  total= days[index];
     int i=index;
     for(;i<n;i++){
          if(total <days[i]){
            break;
          }
     }
     int first=costs[0]+ solve(i,days, costs,n,dp);
     total=days[index]+ 6;
     i=index;
      for(;i<n;i++){
          if(total <days[i]){
            break;
          }
     }
     int second=costs[1]+ solve(i,days, costs,n,dp);
     i=index;
     total=days[index]+ 29;
      for(;i<n;i++){
          if(total <days[i]){
            break;
          }
     }
     int third=costs[2]+ solve(i,days, costs,n,dp);

     return dp[index]=min({first,second,third});

   }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int totaldays=1;
        int index=0;
        int n=days.size();
        vector<int>dp(n,-1);
        return solve(index,days,costs ,n,dp);
    }
};