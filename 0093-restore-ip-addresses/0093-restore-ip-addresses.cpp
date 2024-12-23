class Solution {
public:
    void solve(int index, int n, string s, string pat, int count,
               vector<string>& ans) {
        // all valid
        if (index >= n) {
            // cout << pat << endl;
            if (count == 4) {
                ans.push_back(pat);
            }
            return;
        }

        if (s[index] == '0' && count < 4) {
            solve(index + 1, n, s, pat + "0.", count + 1, ans);
        } else if (s[index] == '1' && count < 4) {
            solve(index + 1, n, s, pat + "1.", count + 1, ans);
            if (index + 1 < n) {
                solve(index + 2, n, s, pat + '1' + s[index + 1] + '.',
                      count + 1, ans);
            }
            if (index + 2 < n) {
                solve(index + 3, n, s,
                      pat + '1' + s[index + 1] + s[index + 2] + '.', count + 1,
                      ans);
            }
        } else if (s[index] == '2' && count < 4) {
            solve(index + 1, n, s, pat + "2.", count + 1, ans);
            if (index + 1 < n) {
                solve(index + 2, n, s, pat + '2' + s[index + 1] + '.',
                      count + 1, ans);
            }
            if (index + 2 < n ) {
                if(s[index+1] <='4'){
                   solve(index + 3, n, s,
                      pat + '2' + s[index + 1] + s[index + 2] + '.', count + 1,
                      ans);
                }
                
                if(s[index+1]=='5' && s[index+2]<='5'){
                     solve(index + 3, n, s,
                      pat + '2' + s[index + 1] + s[index + 2] + '.', count + 1,
                      ans);
                }
               
            }
        } else if (s[index] >= '3' && s[index] <= '9' && count < 4) {
            solve(index + 1, n, s, pat + s[index] + '.', count + 1, ans);
            if (index + 1 < n) {
                solve(index + 2, n, s, pat + s[index] + s[index + 1] + '.',
                      count + 1, ans);
            }
        } else {
            return;
        }
    }
    vector<string> restoreIpAddresses(string s) {

        int index = 0;
        string pat;
        vector<string> ans;
        int n = s.size();
        int count = 0;
        solve(index, n, s, pat, count, ans);
        for (auto& i : ans) {
            i.pop_back();
        }
        return ans;
    }
};