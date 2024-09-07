class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> row(numRows);
        int n = s.length();
        if (n == 1 || numRows==1) {
            return s;
        }
        int j = 0;
        bool flag = true; // means increasing
        for (int i = 0; i < n; i++) {

           row[j].push_back(s[i]);
            if (flag == true) {
                if (j == numRows - 1) {
                    j -= 1;
                    flag = false; // means now decreasing start
                    continue;
                }
                j++;
            } else {
                if (j == 0) {
                    j += 1;
                    flag = true; // now increasing start
                    continue;
                }
                j--;
            }
        }
        s="";
        for (auto l : row) {
            s+= l;
        }
        return s;
    }
};