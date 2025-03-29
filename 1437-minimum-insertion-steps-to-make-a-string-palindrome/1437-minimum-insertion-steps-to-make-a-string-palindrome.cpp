class Solution {
public:
    int longestcommonsubsequence(int i, int j, int m  ,string &olds, string &news ,vector<vector<int>> & dp){

        if(i==m || j==m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(olds[i]== news[j]){
            return dp[i][j]= 1+  longestcommonsubsequence(i+1,j+1,m,olds,news, dp);
        }
        else{
            return dp[i][j]= max( longestcommonsubsequence(i+1,j,m,olds,news, dp) , longestcommonsubsequence(i,j+1,m,olds,news, dp));

        }
    }
    int minInsertions(string s) {
        

        // I have to find the maximum longest match 
        string olds= s;
        reverse(s.begin(),s.end());
        string news=s;
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int matched=  longestcommonsubsequence(0,0,n,olds, news, dp);
        return n-matched;
    }
};