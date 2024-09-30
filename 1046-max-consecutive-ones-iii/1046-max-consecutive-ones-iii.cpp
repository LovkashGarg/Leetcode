class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxlen = 0;
        int zeroes = 0;
        // we make the question as finding the array with at most k no of zeroes
        while (r < n) {

            if (nums[r] == 0)
                zeroes++;

            while (zeroes > k) {

                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            if (zeroes <= k) {
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
       
    return maxlen;
}
};