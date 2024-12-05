class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        // do for each word
        int n = dictionary.size();
        string ans;
        // time complexicity is 0 ( n * d) where n is no of words and d is the size of string 
        int d = s.size();

        for (int i = 0; i < n; i++) {
            // include or not

            int j = 0;
            int k = 0;
            int m = dictionary[i].size();
            while (j < d && k < m) {
                if (s[j] == dictionary[i][k]) {
                    j++;
                    k++;
                } else {
                    j++;
                }
            }

            if (k == m && dictionary[i].size() >= ans.size()) {

                if (dictionary[i].size() == ans.size()) {
                    ans = (ans > dictionary[i] ? dictionary[i] : ans);
                } else {
                    ans = dictionary[i];
                }
            }
        }
        return ans;
    }
};