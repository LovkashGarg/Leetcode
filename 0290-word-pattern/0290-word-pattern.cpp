class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m;
        vector<string> d;
        for (int i = 0; i < s.length(); i++) {
            int j = i;
            string temp;
            while (j < s.length() && s[j] != ' ') {
                temp += s[j];
                j++;
            }
            i = j;
            d.push_back(temp);
        }
        if (pattern.length() != d.size()) {
            return false;
        }
        for (int i = 0, j = 0; j < pattern.length() && i < d.size(); i++, j++) {

            if (m.find(pattern[j]) != m.end()) {

                if (m[pattern[j]] != d[i]) {
                    return false;
                }
                char key = pattern[j];
                for (auto l : m) {
                    if (l.second == d[i]) {
                        key = l.first;
                        break;
                    }
                }
                if (key != pattern[j]) {
                    return false;
                }
            } else {
                char key=pattern[j];
                 for (auto l : m) {
                    if (l.second == d[i]) {
                        key = l.first;
                        break;
                    }
                }
                if(pattern[j]!=key){
                    return false;
                }
                m[pattern[j]] = d[i];
            }
        }
        return true;
    }
};