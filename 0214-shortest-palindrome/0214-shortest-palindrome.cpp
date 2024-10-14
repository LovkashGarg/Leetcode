class Solution {
public:
vector<int> computeLPS(string s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

string shortestPalindrome(string s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    string combined = s + "$" + reversed_s;
    // Compute LPS array 
    vector<int> lps = computeLPS(combined);
    // Get the length
    int longest_palindromic_prefix = lps.back();

    // The remaining part needs to be added to the front to form a palindrome
    string suffix_to_add = s.substr(longest_palindromic_prefix);
    reverse(suffix_to_add.begin(), suffix_to_add.end());

    return suffix_to_add + s;
}
};