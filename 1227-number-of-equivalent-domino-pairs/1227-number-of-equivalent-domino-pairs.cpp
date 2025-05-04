class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        map<pair<int, int>, int> m;
        int n = dominoes.size();
        int count = 0;
        for (int i = 0; i < n; i++) {

            if (m[{dominoes[i][0], dominoes[i][1]}]) {
                count += m[{dominoes[i][0], dominoes[i][1]}];
            } else if (m[{dominoes[i][1], dominoes[i][0]}]) {
                count += m[{dominoes[i][1], dominoes[i][0]}];
            }
            if (dominoes[i][0] == dominoes[i][1]) {
                m[{dominoes[i][0], dominoes[i][1]}]++;
            } else {
                m[{dominoes[i][0], dominoes[i][1]}]++;
                m[{dominoes[i][1], dominoes[i][0]}]++;
            }
        }
        return count;
    }
};