class Solution {
public:
int solve(int index, int diff , vector<int>&nums, vector<unordered_map<int,int>> &mp){
    
    int n=nums.size();
    if(index>=n){
        return 0;
    }

    if(mp[index].count(diff)){
        return mp[index][diff];
    }
   
    // check all the next index
    int count=0;
    for(int j=index+1;j<n;j++){
        int newdiff=nums[j]-nums[index];

        if(newdiff==diff){
        count=max(count, 1 + solve(j,newdiff,nums,mp));
        }


    }

    return mp[index][diff]=count;

}
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=2){
            return n;
        }
        vector<unordered_map<int,int>> dp(n+1);
        // two loops represent all the pairs 
        int ans=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
           int diff= nums[i]-nums[j];
            // If there exists a sequence ending at 'j' with the same difference, extend it
           dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;

                // Update answer
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};