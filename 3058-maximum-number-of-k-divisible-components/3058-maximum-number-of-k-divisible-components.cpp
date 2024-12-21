class Solution {
public:
    int count = 0;
    int dfs(int root, int parent, vector<vector<int>>& adj, int n,
            vector<int>& values, int k) {

        // I have to return the sum of each
        int sum = 0;
        for (auto adj_node : adj[root]) {

            if (adj_node != parent) {
                sum += dfs(adj_node, root, adj, n, values, k);
                sum %= k;
            }
        }

        sum += values[root];
        sum %= k;
        if (sum == 0) {
            count++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        // do dfstraversal
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        dfs(0, -1, adj, n, values, k);
        return count;
    }
};