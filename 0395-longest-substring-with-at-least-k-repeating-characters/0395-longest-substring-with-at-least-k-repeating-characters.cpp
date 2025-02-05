class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

    int helper(string &s, int start, int end, int k) {

        // no fayda 
        if (end - start < k) return 0; // If substring is smaller than k, return 0

        vector<int> freq(26, 0);
        for (int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = start; i < end; i++) {

            // agar yeh alphabet hoga to kabhi bhi valid nhi aayega 
            if (freq[s[i] - 'a'] > 0 && freq[s[i] - 'a'] < k) {


                // Found an invalid character; split around it
                int left = helper(s, start, i, k);
                int right = helper(s, i + 1, end, k);
                return max(left, right);
            }
        }

        return end - start; // If all characters are valid, return the full length
    }
};
