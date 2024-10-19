class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        // Building the adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int finalans = INT_MAX;
        
        // BFS to find the shortest cycle
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);  // Distance from node i
            vector<int> parent(n, -1);  // To track the parent of each node
            queue<int> q;
            
            dist[i] = 0;
            q.push(i);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    // If neighbor hasn't been visited 
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    }
                    // If the neighbor has been visited and it's not the parent of the current node
                    else if (parent[node] != neighbor) {
                        // Found a cycle
                        finalans = min(finalans, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }
        
        return (finalans == INT_MAX) ? -1 : finalans;
    }
};
