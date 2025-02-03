class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {
                int len = 1;

                // increasing
                int val = nums[i];
                for (int k = i + 1; k <= j; k++) {
                    //
                    if (nums[k] > nums[k - 1]) {
                        len++;
                    } else {
                        break;
                    }
                }
                maxlen = max(maxlen, len);
                len = 1;
                // decreasing
                for (int k = i + 1; k <= j; k++) {
                    //
                    if (nums[k] < nums[k - 1]) {
                        len++;
                    } else {
                        break;
                    }
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};