class Solution {
public:
    int countPrimes(int n) {

        // here catch is to
        vector<bool> v(n, false);
        int count = 0;
        for (int i = 2; i < n; i++) {

            // 2 is prime therefore mark all its multiple as non prime
            // 3  similarly

            if (v[i] == false) {
                count++;
                for (int j = 2; i * j < n; j++) {
                    // means this number is not  prime
                    v[i * j] = true;
                }
            }
            // if one is prime then all its multiple are
        }
        return count;
    }
};