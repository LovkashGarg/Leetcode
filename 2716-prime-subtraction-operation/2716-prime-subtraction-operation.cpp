class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        // Generate primes up to maxi
        vector<bool> prime(maxi + 1, true);
        for (int p = 2; p * p <= maxi; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= maxi; i += p) {
                    prime[i] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= maxi; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }

        // Traverse from the end to the start to ensure strictly increasing order
        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] >= nums[i + 1]) {
                // if agar same hi rahega to nikal hi do 
                bool found = false;
                for (int j = 0; j < primes.size() && primes[j] < nums[i]; j++) {
                    if (nums[i] - primes[j] < nums[i + 1]) {
                        nums[i] -= primes[j];
                        found = true;
                        break;
                    }
                }
                if (!found) return false; // If no valid prime subtraction found
            }
        }

        return true;
    }
};
