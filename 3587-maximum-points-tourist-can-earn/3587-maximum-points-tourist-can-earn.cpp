class Solution {
public:
    int solve(int currcity,int currday,vector<vector<int>>& stayScore, vector<vector<int>>& travelScore,int n,int k,vector<vector<int>>&dp){
        if(currday==k){
            return 0;
        }
        if(dp[currcity][currday]!=-1){
            return dp[currcity][currday];
        }
// now solve for next day 
        int stay=stayScore[currday][currcity] + solve(currcity,currday+1,stayScore,travelScore,n,k,dp);

        // now it might be possible i want to travel to another city 
        int travel=INT_MIN;
    
        for(int i=0;i<n;i++){
            if(i!=currcity){
             int traveloption= travelScore[currcity][i] + solve(i,currday+1,stayScore,travelScore,n,k,dp);
              travel = max(travel, traveloption);
            }
        }
        return  dp[currcity][currday]=max(stay,travel);

    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        // here n is no of cities and k is no of days 
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans=INT_MIN;
        for(int  city=0;city<n;city++){
            dp[city][0]=solve(city,0,stayScore,travelScore,n,k,dp);
            ans=max(ans,dp[city][0]);
        }
        return max(ans,0);
    }
};