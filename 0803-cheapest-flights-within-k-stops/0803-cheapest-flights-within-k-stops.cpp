class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto j:flights){
            adj[j[0]].push_back({j[2],j[1]});
        }

        queue<pair<int,pair<int,int>>>q;
        // we do need a priority queue since our stops are always sorted and are increasing 
        // stops, node , cost

        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
      while(!q.empty()){
        int stops=q.front().first;
        int node=q.front().second.first;
        int cost= q.front().second.second;
        q.pop();

        if(stops >k){
            continue;
        }
        for(auto j: adj[node]){
            int edgewe=j.first;
            int adj_node=j.second;

            if(cost+ edgewe <=dist[adj_node] && stops<=k){
            dist[adj_node]=cost + edgewe;
            q.push({stops +1,{adj_node, cost + edgewe}});
            }
        }
      }
      if(dist[dst]==1e9){
        return -1;
      }
      return dist[dst];
    }
};