class Solution {
public:
    string minWindow(string s, string t) {
       if (s.empty() || t.empty()) {
            return "";
        }
        int l = 0;
        int r = 0;
        // preinsert all the values
        int minlen=1e9;
        int sindex=-1;
        vector<int> hash(256, 0);
        int cnt = 0;
        for (int i = 0; i < t.length(); i++) {
            hash[t[i]]++;
        }

        while (r < s.length()) {
            if (hash[s[r]] > 0) {
                cnt = cnt + 1;
            }
            hash[s[r]]--;

            while (cnt == t.size()) {
                if ((r - l + 1) < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }
                // Now decreasing start
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt = cnt - 1;
                }
                l++;    
            }
            r++;
        }
        return sindex==-1 ? "": s.substr(sindex,minlen);
    }
};