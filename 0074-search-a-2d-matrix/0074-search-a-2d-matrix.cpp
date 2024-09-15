class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowrow = 0;
        int highrow = matrix.size()-1;
        while (lowrow <= highrow) {
            int lowcol = 0;
            int highcol = matrix[0].size()-1;
            int midrow = (lowrow + highrow) / 2.0;
            if (matrix[midrow][lowcol] <= target &&
                target <= matrix[midrow][highcol]) {
                while (lowcol <= highcol) {
                    int midcol = (lowcol + highcol) / 2.0;
                    if (matrix[midrow][midcol] == target) {
                        return true;
                    } else if (matrix[midrow][midcol] < target) {
                        lowcol = midcol + 1;
                    } else {
                        highcol = midcol - 1;
                    }
                }
                return false;
            } else if (matrix[midrow][lowcol] > target) {
                highrow = midrow - 1;
            } else {
                lowrow = midrow + 1;
            }
        }
        return false;
    }
};