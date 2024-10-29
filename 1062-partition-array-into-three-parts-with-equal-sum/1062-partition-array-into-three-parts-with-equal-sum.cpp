class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if (sum % 3 == 0) {
            long long int sumreq = sum / 3;
           long  long int sumcurr = 0;
            int count = 0;
            for (int i = 0; i < n; i++) {
                sumcurr += arr[i];
                if (sumcurr == sumreq) {
                    count++;
                    sumcurr = 0;
                }
            }
            if (count >= 3) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};