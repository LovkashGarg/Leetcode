class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {

        string seclast;
        string firstlast;

        int i = 0;
        int n = text.size();
        vector<string> ans;
        while (i < n) {
            string curr;
            while (i < n && text[i] != ' ') {
                curr += text[i];
                i++;
            }

            if (firstlast == second && seclast == first) {
                ans.push_back(curr);
            }
            seclast = firstlast;
            firstlast = curr;
            i++;
        }
        return ans;
    }
};