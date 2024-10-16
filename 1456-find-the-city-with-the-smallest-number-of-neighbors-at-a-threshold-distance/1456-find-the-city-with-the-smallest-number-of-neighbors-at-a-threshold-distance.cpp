class Solution {
public:
// time complexicity --> 0(n^3)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for (auto i : edges) {
            // undirected graph
            adj[i[0]][i[1]] = i[2];
            adj[i[1]][i[0]] = i[2];
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        int finalans = n;
        int index = 0;
        for (int i = 0; i < adj.size(); i++) {
            int ans = 0;
            for (int j = 0; j < adj[i].size(); j++) {
                if (adj[i][j] <= distanceThreshold) {
                    ans++;
                }
            }
            if (ans <= finalans) {
                index = i;
                finalans = min(finalans, ans);
            }
        }
        return index;
    }
};