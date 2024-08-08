class Solution {
public:
    string frequencySort(string s) {
        vector<vector<char>> bucket(s.length() + 1);
        map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        int maxi = 0;
        for (auto j : m) {
            bucket[j.second].push_back(j.first);
            maxi = max(maxi, j.second);
        }
        int k = 0;
        string ans;
        for (int i = maxi; i >= 1; i--) {
            // we are done
            if (k == n) {
                break;
            }
            for (auto j : bucket[i]) {
                // here first argument is no and second is character
                string d = string(i, j);
                ans += d;
                k += i;
            }
        }
        return ans;
    }
    string frequencySort2(string s) {
        vector<vector<char>> bucket(s.length() + 1);
        vector<int> frq(62, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] >= 97 && s[i] <= 122) {
                frq[s[i] - 'a']++;
            } else if (s[i] >= 65 && s[i] <= 90) {
                frq[s[i] - 'A' + 26]++;
            } else if (s[i] >= 48 && s[i] <= 57) {
                frq[s[i] - '0' + 52]++;
            }
        }
        int maxi = 0;
        for (int i = 0; i < 62; i++) {
            // cout<<m[i+'a']
            if (i < 26) {
                bucket[frq[i]].push_back(i + 'a');
            } else if (i >= 26 && i < 52) {
                bucket[frq[i]].push_back(i - 26 + 'A');
            } else {
                bucket[frq[i]].push_back(i - 52 + '0');
            }
            maxi = max(maxi, frq[i]);
        }
        string ans;
        int k = 0;
        for (int i = maxi; i >= 1; i--) {
            if (k == n) {
                // cout<<"hello"<<endl;
                break;
            }
            // cout<<"frequency "<<i<<endl;
            for (auto j : bucket[i]) {
                string d = string(i, j);
                ans += d;
                k += i;
            }
        }
        return ans;
    }
};