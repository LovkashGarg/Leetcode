class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        // make the person he dislike the adjacent elements to the person and if
        // I am not able to colour it or mean the graph is not Bipartite then

        vector<vector<int>> adj(n + 1);
        for (auto i : dislikes) {
            // iska matlab adjacent hai yeh
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> color(n + 1, -1);

        // I assigned him group 0

        // I have to do
        for (int i = 1; i <= n; i++) {

            // matlab disconnected component hai or uska color nhi diya gya to
            // usko color dedo
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool dfs(int node, int c, const vector<vector<int>>& adj,
             vector<int>& color) {
        color[node] = c; // give him the group

        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                // usko color dedo
                if (!dfs(neighbor, !c, adj, color)) {
                    return false;
                }
            } else if (color[neighbor] == c) {
                return false;
            }
        }
        return true;
    }
};