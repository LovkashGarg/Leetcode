class Solution {
public:
    int solve(string text1, string text2, int i, int j, int n1, int n2) {
        if (i >= n1 || j >= n2) {
            return 0;
        }
        if (text1[i] == text2[j]) {
            return 1 + solve(text1, text2, i + 1, j + 1, n1, n2);
        } else {
            return max(solve(text1, text2, i + 1, j, n1, n2),
                       solve(text1, text2, i, j + 1, n1, n2));
        }
    }
    // note & is very important since may lead to TLE
    int solvedp(string& text1, string& text2, int i, int j,
                vector<vector<int>>& dp) {
        if (i == text1.length())
            return 0;
        if (j == text2.length())
            return 0;
        

        if (dp[i][j] != -1) {
            return dp[i][j]; // here dp[i][j] means what would be the ans if the
                             // string is limited to this range only
        }

        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solvedp(text1, text2, i + 1, j + 1, dp);
        } else {
            ans = max(solvedp(text1, text2, i + 1, j, dp),
                      solvedp(text1, text2, i, j + 1, dp));
        }


        return dp[i][j] = ans;
    }
    int solvetabulation(string& text1, string& text2) {
        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, 0));


         
         int ans = 0;
        for (int i = text1.length() - 1; i >= 0; i--) {
            for (int j = text2.length() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    ans = 1 + dp[i + 1][j + 1];

                } else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j]=ans;
            }
        }

        return dp[0][0];
    }

    int solvespace(string & text1,string & text2){
        // length would be equal to number of coulmuns;
        vector<int > curr(text2.length()+1,0);
        vector<int> next(text2.length()+1,0);

        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                  curr[j]=1+ next[j+1];
                }
                else{
                    curr[j]=max(next[j],curr[j+1]);
                }
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        // return solve(text1,text2,0,0,n1,n2);
        // return solvedp(text1, text2, 0, 0, dp);
        return solvetabulation(text1,text2);
        // return solvespace(text1,text2);
    }
};