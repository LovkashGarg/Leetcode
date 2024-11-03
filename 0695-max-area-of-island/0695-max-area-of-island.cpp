class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& board,
             vector<vector<int>>& visited, int& count) {
        visited[i][j] = 1;
        count++;
        if (i >= 0 && i + 1 < n && j >= 0 && j < m && visited[i + 1][j] != 1 &&
            board[i + 1][j] == 1) {
            dfs(i + 1, j, n, m, board, visited, count);
        }
        if (i >= 0 && i < n && j >= 0 && j + 1 < m && visited[i][j + 1] != 1 &&
            board[i][j + 1] == 1) {
            dfs(i, j + 1, n, m, board, visited, count);
        }
        if (i - 1 >= 0 && j < m && i < n && j >= 0 && visited[i - 1][j] != 1 &&
            board[i - 1][j] == 1) {
            dfs(i - 1, j, n, m, board, visited, count);
        }

        if (i >= 0 && i < n && j - 1 >= 0 && j < m && visited[i][j - 1] != 1 &&
            board[i][j - 1] == 1) {
            dfs(i, j-1, n, m, board, visited, count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] != 1 && board[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, n, m, board, visited, count);
                    // cout << count << endl;
                    ans = max(count, ans);
                }
            }
        }
        return ans;
    }
};