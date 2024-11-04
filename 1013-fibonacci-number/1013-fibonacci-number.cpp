class Solution {
public:
    vector<int> m;  // Declare m without initializing here

    Solution() : m(100, -1) {}  // Initialize m in the constructor

    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        if (m[n] != -1) {
            return m[n];
        }
        
        m[n] = fib(n - 1) + fib(n - 2);
        return m[n];
    }
};
