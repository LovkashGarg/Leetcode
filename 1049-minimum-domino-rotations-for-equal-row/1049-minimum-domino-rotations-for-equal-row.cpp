class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int n = tops.size();
        int ans = INT_MAX;

        for (int i = 1; i <= 6; i++) {

            bool flag = true;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (tops[j] == i) {
                    continue;
                } else if (bottoms[j] == i) {
                    count++;
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                ans = min(ans, count);
            }
        }

        for (int i = 1; i <= 6; i++) {

            bool flag = true;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (bottoms[j] == i) {
                    continue;
                } else if (tops[j] == i) {
                    count++;
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                ans = min(ans, count);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};