class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

int l = 0, r = 0, ans = 1, n = nums.size();
        int bitMask = 0;
        while (r < n) {
                while ((bitMask & nums[r]) != 0) { 
                bitMask ^= nums[l];  // would reset all its all the bits
                l++; 
            }

            // would set all the bits of bit Mask and take the num[r] in the subarray
            bitMask |= nums[r];

            ans = max(ans, r - l + 1);
            r++;

        }
        
        return ans;
    }
};