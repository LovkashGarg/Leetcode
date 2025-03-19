class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        int maxarea = 0;
        vector<int> currcol(m, 0);
        vector<int> prevcol(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    currcol[j] = 0;
                } else {
                    currcol[j] = prevcol[j] + 1;
                }
            }

            stack<int> s;
            vector<int> pse(m);
            for (int k = 0; k < m; k++) {

                while (!s.empty() && currcol[k] < currcol[s.top()]) {
                    // here I want to get the value

                    int height = currcol[s.top()];
                    int width = k - pse[s.top()] - 1;
                    int side = min(height, width);
                    maxarea = max(maxarea, side * side);

                    s.pop();
                }

                if (s.empty()) {
                    pse[k] = -1;
                } else {
                    pse[k] = s.top();
                }

                s.push(k);
            }

            while (!s.empty()) {

                int width = m - pse[s.top()] - 1;
                int height = currcol[s.top()];
                
                int side = min(height, width);
                maxarea = max(maxarea, side * side);

                s.pop();
            }

            prevcol = currcol;
        }
        return maxarea;
    }
};