class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        set<string> s;
        unordered_map<string, int> m;
        int j = 0;
        for (int i = 0; i < equations.size(); i++) {
            if (m.find(equations[i][0]) == m.end()) {
                m[equations[i][0]] = j;
                j++;
            }
            if (m.find(equations[i][1]) == m.end()) {
                m[equations[i][1]] = j;
                j++;
            }
            s.insert(equations[i][0]);
            s.insert(equations[i][1]);
        }
        // no of variables
        int n = s.size();
        vector<vector<double>> div(n, vector<double>(n, -1));
        for (int i = 0; i < n; i++) {
            div[i][i] = 1;
        }
        for (int i = 0; i < equations.size(); i++) {
            div[m[equations[i][0]]][m[equations[i][1]]] = values[i];
            div[m[equations[i][1]]][m[equations[i][0]]] =
                (double(1.0) / values[i]);
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << div[i][j] << " ";
        //     }
        //     cout << endl;
        // }

          // Floyd-Warshall algorithm to compute all-pairs reachability
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (div[i][k] != -1 && div[k][j] != -1) {
                        div[i][j] = div[i][k] * div[k][j];
                        double newVal=div[i][j];
                         // Apply precision threshold during matrix update
                        if (abs(newVal - 1.0) < 1e-5) {
                            newVal = 1.0;
                        }
                        div[i][j] = newVal;
                    }
                }
            }
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            
            if (s.find(queries[i][0]) == s.end() ||
                s.find(queries[i][1]) == s.end()) {
                // cout << "Not found" << endl;
                // cout << i << queries[i][0] << queries[i][1] << endl;
                ans.push_back(-1);
                continue;
            }

                double result =div[m[queries[i][0]]][m[queries[i][1]]];
                if(result <0){
                    ans.push_back(result);
                    continue;
                }
 // Apply a precision threshold
                if (abs(result - 1.0) < 1e-5) {
                    result = 1.0; // Round to 1.0 if very close
                }
                // cout << i << queries[i][0] << queries[i][1] << endl;
                ans.push_back(result);
        
        }
        return ans;
    }
};