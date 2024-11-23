class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = box[j][i];
            }
        }

        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; i++) {
            reverse(ans[i].begin(), ans[i].end());
        }

    
        for (int j = 0; j < m; j++) {
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                if (ans[i][j] == '.') {  // Found an empty cell; check if a
                                            // stone can fall into it
                    int nextRowWithStone = -1;

                    
                    for (int k = i - 1; k >= 0; k--) {
                        if (ans[k][j] == '*')
                            break; 
                        if (ans[k][j] == '#') { 
                            nextRowWithStone = k;
                            break;
                        }
                    }

                   
                    if (nextRowWithStone != -1) {
                        ans[nextRowWithStone][j] = '.';
                        ans[i][j] = '#';
                    }
                }
            }
        }
        return ans;
    }
};