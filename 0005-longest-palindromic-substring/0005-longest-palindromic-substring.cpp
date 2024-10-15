class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        if (s.length() == 1) {
            return s;
        }
        res+=s[0];
        for (int i = 0; i < s.length(); i++) {
            int l = i - 1, r = i + 1;
            string ans;
            ans += s[i];
            // res=ans;
            // expanding from center
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                ans = s[l] + ans + s[r];
                l--;
                r++;
                if (ans.length() >= res.length()) {
                    res = ans;
                }
            }

            l = i;
            r = i + 1;
            ans = "";
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                ans = s[l] + ans + s[r];
                l--;
                r++;
                if (ans.length() >= res.length()) {
                    res = ans;
                }
            }
            cout<<res<<endl;
        }
        return res;
    }
};