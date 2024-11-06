class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        // here we would apply bfs
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> safePoints(n, vector<int>(m, 0));
        int col = 0;
        
        for (int i = 0; i < n; i++) {
            if (maze[i][col] != '+') {
                safePoints[i][col] = 1;
            }
        }

        col = m - 1;
        for (int i = 0; i < n; i++) {
            if (maze[i][col] != '+') {
                safePoints[i][col] = 1;
            }
        }
        int row = 0;
        for (int i = 0; i < m; i++) {
            if (maze[row][i] != '+') {
                safePoints[row][i] = 1;
            }
        }
        row = n - 1;
        for (int i = 0; i < m; i++) {
            if (maze[row][i] != '+') {
                safePoints[row][i] = 1;
            }
        }
        safePoints[entrance[0]][entrance[1]] = 0;
        int level = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        visited[entrance[0]][entrance[1]] = 1;
          vector<int> dirrow = {1, 0, -1, 0};
         vector<int> dircol = {0, -1, 0, 1}; 
        while (!q.empty()) {

            int d = q.size();
            for (int i = 0; i < d; i++) {

                int rowx = q.front().first;
                int rowy = q.front().second;
                // visited[rowx][rowy]=1;
                // cout<<rowx<<rowy<<endl;
                q.pop();

                if (safePoints[rowx][rowy] == 1) {
                    return level;
                }

              

                for (int j = 0; j < 4; j++) {
                    int newrow = rowx + dirrow[j];
                    int newcol = rowy + dircol[j];
                    if (newrow >= 0 && newrow < n && newcol >= 0 &&
                        newcol < m && maze[newrow][newcol] == '.' && visited[newrow][newcol]==0) {
                        q.push({newrow, newcol});
                        // since other level element could aso be visiting the same element 
                         visited[newrow][newcol] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};