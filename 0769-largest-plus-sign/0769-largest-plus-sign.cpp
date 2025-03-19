class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto i : mines) {

            grid[i[0]][i[1]] = 0;
        }

        vector<vector<int>> row_l_r(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    row_l_r[i][j] = 0;
                    val = 0;

                } else {
                    val++;
                    row_l_r[i][j] = val;
                }
            }
        }

        vector<vector<int>> row_r_l(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {

            int val = 0;

            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {

                    row_r_l[i][j] = 0;
                    val = 0;

                } else {

                    val++;
                    row_r_l[i][j] = val;
                }
            }
        }

        vector<vector<int>> col_u_d(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 0) {
                    val = 0;
                    col_u_d[j][i] = val;
                } else {
                    val++;
                    col_u_d[j][i] = val;
                }
            }
        }

        vector<vector<int>> col_d_u(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = n - 1; j >= 0; j--) {

                if (grid[j][i] == 0) {
                    val = 0;
                    col_d_u[j][i] = val;
                }

                else {
                    val++;
                    col_d_u[j][i] = val;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    int mini1 = min(row_l_r[i][j], row_r_l[i][j]);
                    int mini2 = min(col_u_d[i][j], col_d_u[i][j]);
                    ans = max(ans, min(mini1, mini2));
                }
            }
        }

        return ans;
    }
};