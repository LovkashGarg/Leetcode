class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.size();
        vector<int> ans;
        // for ehre I can do the
        for (int i = 0; i < n; i++) {

            // i can check for the least index till which we have 1

            // for right
            int right=0;
            for (int j = n - 1; j > i; j--) {
                // here fir st I have to add the
                if (boxes[j] == '1') {
                    right += j-i;
                }
            }

            // for left
            int left = 0;
            for (int j = 0; j < i; j++) {
                if (boxes[j] == '1') {
                    left += i-j;
                }
            }
            ans.push_back(left+ right);
        }

        return ans;
    }
};