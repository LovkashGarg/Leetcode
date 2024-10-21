class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> ans;
        int n = pattern.size();
        for (int k = 0; k < words.size(); k++) {

            unordered_map<char, char> m;
            vector<int> v(256, -1);
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (m.find( words[k][i]) != m.end() && m[words[k][i]] != pattern[i]) {
                    flag = false;
                    break;
                }
                // agar key nhi hai map me to then
                if (m.find(words[k][i]) == m.end()) {
                    // already mapped hai to some other character  to return
                    // false
                    if (v[pattern[i]] == 1) {
                        flag = false;
                        break;
                    }
                    v[pattern[i]] = 1;
                    m[words[k][i]] = pattern[i];
                }
            }
            if (flag == true) {
                ans.push_back(words[k]);
            }
        }
        return ans;
        }
};