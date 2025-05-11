class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        int count = 0;
        while (i < n) {
            if (arr[i] % 2 == 0) {
                i++;
                count = 0;
            } else {
                count++;
                i++;
            }

            if (count >= 3) {
                return true;
            }
        }
        return false;
    }
};