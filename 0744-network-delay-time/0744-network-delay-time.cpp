class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(k==1 && n==1){
            return 0;
        }
        vector<pair<int, int>> adj[n + 1];
        for (auto j : times) {
            adj[j[0]].push_back({j[2], j[1]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
        pq.push({0, k});
        vector<int> dist(n + 1, 1e9);
        dist[k]=0;
        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto j : adj[node]) {
                int edgewe = j.first;
                int adj_node = j.second;

                if (distance + edgewe < dist[adj_node]) {
                    dist[adj_node] = distance + edgewe;
                    pq.push({dist[adj_node], adj_node});
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
          if(dist[i]==1e9){
            return -1;
          }
          else{
            if(i!=k)
            ans=max(ans,dist[i]);
          }
        }
        return ans;
    }
};