class Solution {
public:
    long long int mod = int(1e9) + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto j : roads) {
            adj[j[0]].push_back({j[1], j[2]});
            adj[j[1]].push_back({j[0], j[2]});
        }

        priority_queue<pair<long int, int>, vector<pair<long int, int>>,
                       greater<pair<long int, int>>>
            pq;
        vector<long int> dist(n, LONG_MAX);
        vector<long int> ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto distance = pq.top().first;
            auto node = pq.top().second;

            pq.pop();

            for (auto j : adj[node]) {
                auto edgewe = j.second;
                auto adj_node = j.first;
                // this is the first time I am arriving at the node
                // with this  short path
                if (distance + edgewe < dist[adj_node]) {
                    dist[adj_node] = distance + edgewe;
                    pq.push({dist[adj_node], adj_node});
                    ways[adj_node] = ways[node];
                } else if (distance + edgewe == dist[adj_node]) {
                    ways[adj_node] = (ways[adj_node] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};