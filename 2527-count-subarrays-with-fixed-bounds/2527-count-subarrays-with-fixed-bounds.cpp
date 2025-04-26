class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {

        int maxstart = 0;
        int minstart = 0;
        bool minpresent = false;
        bool maxpresent = false;

        long long count = 0;
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++) {

            // means in this subarray we cant form the required subarray
            if (nums[i] < mink || nums[i] > maxk) {
                minpresent = false;
                maxpresent = false;
                start = i + 1;
            }

            // mink found
            if (nums[i] == mink) {
                minstart = i;
                minpresent = true;
            }

            // maxk found
            if (nums[i] == maxk) {
                maxstart = i;
                maxpresent = true;
            }

            // both are present now I need to check the number of subarray formed
            if (maxpresent && minpresent) {
                count += (min(maxstart, minstart) - start + 1);
            }
        }
        return count;
    }
};