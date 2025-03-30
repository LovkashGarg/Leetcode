class Solution {
public:
  int solve_tabulation(int m ,int n,  string &s1, string &s2,  vector<vector<int>>&dp){

   
    // since dp[2][3] means lcs for string 0 to 1 index and 0 to 2 
    // so dp[0][2] means no character from string1 and 0 to 1 index for string 2
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }

    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=m;i++){
       for(int j=1;j<=n;j++){
        
        if(s1[i-1]==s2[j-1]){
            dp[i][j]= 1+ dp[i-1][j-1];
        }
        else{
            dp[i][j]= max(dp[i-1][j] , dp[i][j-1]);
        }
       }
    }

    return dp[m][n];

}

    string constructstring(string &str1, string &str2, vector<vector<int>> &dp) {
        int m = str1.size(), n = str2.size();
        int i = m, j = n;
        string ans = "";

        while (i >0 && j >0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j-1]) {
                ans+=str1[i-1];
                i--;
            } else {
                ans+=str2[j-1];
                j--;
            }
        }

        // Append remaining characters
        while (i >0){
 ans += str1[i - 1];
 i--;
        }
        while (j >0){
ans += str2[j - 1];
j--;
        } 

        reverse(ans.begin(),ans.end());

        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
         solve_tabulation(m,n,str1,str2,dp);
        return constructstring(str1, str2, dp);
    }
};
