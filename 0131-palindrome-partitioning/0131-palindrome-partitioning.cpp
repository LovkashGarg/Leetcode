class Solution {
public:
    vector<vector<string>> ans;
    void solve(string s, int index, int n, vector<string> output) {
        if (index >= n) {
            ans.push_back(output);
            return;
        }

        string d;
        for (int i = index; i < n; i++) {
            d += s[i];
            output.push_back(d);
            solve(s, i + 1, n, output);
            output.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {

        // generate all pssible sequences

        int n = s.size();
        vector<string> output;
        solve(s, 0, n, output);
      vector<vector<string>>finalans;
        for (auto& st : ans) {
            cout<<st.size()<<endl;
            bool flag = true;
            for (auto &l : st) {
                int m = l.size();
                for (int i = 0; i < m/2; i++) {
                    cout<<l[i]<<" "<<l[m-i-1]<<endl;
                    if (l[i] != l[m - i - 1]) {
                        flag = false;
                        break;
                    }
                }

               
                if(flag==false){
                    break;
                }
            }
            
            if(flag==true){
                finalans.push_back(st);
            }
        }

        return finalans;
    }
};