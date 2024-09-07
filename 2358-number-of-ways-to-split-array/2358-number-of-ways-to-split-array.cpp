class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long int > prefixsum(n);
        prefixsum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixsum[i] = nums[i] + prefixsum[i - 1];
        }
        long long int sum = prefixsum[n - 1];
        int cntways = 0;
        for (int i = 0; i < n - 1; i++) {
            // cout << prefixsum[i] << " " << (sum - prefixsum[i]) << endl;
            if (prefixsum[i] >= sum - prefixsum[i]) {
                // cout<<"one more split "<<endl;
                cntways++;
            }
        }
        return cntways;
    }
};