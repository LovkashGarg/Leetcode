class Solution {
public:
    int solve(string &s ,string & p , int i , int j , vector<vector<int>> & dp,int m,int n){

// both finished 
        if(i==m && j==n){
            return 1;
        }


// means i is still pending so we not match 
        if(j==n){
            return 0; 
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

       if(j+1<n && p[j+1]=='*'){
// not include and  current match kargya hai or ham ja rhe hai 
         return  dp[i][j]=((solve(s,p, i, j+2,dp,m,n )) || (match && solve(s,p,i+1,j,dp,m,n)  ) );
       }

       if(match){
        return dp[i][j]=solve(s,p,i+1,j+1,dp,m,n);
       }
         
       return dp[i][j]=0;

    }
    bool isMatch(string s, string p) {
             
             int m=s.size();
             int n=p.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1, -1));
        return solve(s,p, 0,0,dp,m,n);
    }
};