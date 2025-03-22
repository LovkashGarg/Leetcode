class Solution {
public:
    void spiralme(vector<vector<int>>& matrix, int left, int right, int top,
                  int bottom, vector<int>& ans) {
        // left to right
        // cout << "LTR" << endl;
        // cout << left << right << top << bottom << endl;

        for (int i = left; i <= right; i++) {
            if (top > bottom) {
                break;
            }
            cout << matrix[top][i] << endl;
            ans.push_back(matrix[top][i]);
        }
        top++;
        cout << "TTB" << endl;
        cout << left << right << top << bottom << endl;
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << endl;
            ans.push_back(matrix[i][right]);
        }
        right--;

        // cout << "RTL" << endl;
        // cout << left << right << top << bottom << endl;

        
        // for only one *m array then it would break out of the line  since top is coming to next line but bottom is still there therefore it would traverse again 
        if (top <= bottom) {

            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << endl;
                ans.push_back(matrix[bottom][i]);
            }


            bottom--;
            cout << "BTT" << endl;
            cout << left << right << top << bottom << endl;
            for (int i = bottom; i >= top; i--) {
                if (left > right) {
                    break;
                }
                cout << matrix[i][left] << endl;
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        if (left <= right) {
            spiralme(matrix, left, right, top, bottom, ans);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> ans;
        spiralme(matrix, left, right, top, bottom, ans);
        return ans;
    }
};