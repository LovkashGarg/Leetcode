class Solution {
public:

int solve(int i,int j, int m, int n , string & s, string &t,vector<vector<int>> & dp){

    if(i==m){
        // means we have attained the t
        if(j==n){
          return 1;
        }
        else{
            return 0;
        }
    }


if(dp[i][j]!=-1){
    return dp[i][j];
}


int include=0;
    if(s[i]==t[j]){
      
    //there are two  ways 
    // include this or not include this 

    include = solve(i+1,j+1,m,n,s,t,dp);

    }

   int exclude= solve(i+1,j,m,n,s,t,dp);

    return dp[i][j]=exclude + include;
}
// here I need to find all the subsequence of s which are equal to t 
    int numDistinct(string s, string t) {
        int m= s.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,s,t,dp);
    }
};