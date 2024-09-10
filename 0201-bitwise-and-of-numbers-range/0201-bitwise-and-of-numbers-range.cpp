class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

       while (left < right) {
            // Remove the least significant bit that differs between left and right
            right = right & (right - 1);
        }
        return left & right;
    }
};