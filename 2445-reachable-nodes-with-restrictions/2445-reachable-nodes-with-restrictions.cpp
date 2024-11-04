class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<int>restrict(n,0);
        for(int i=0;i<restricted.size();i++){
            restrict[restricted[i]]=1;
        }
        for (auto i : edges) {
            
            // both of them are not in restricted
            if(restrict[i[0]]== 0 && restrict[i[1]]==0){
                // cout<<i[0]<<" "<<i[1]<<endl;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            }
            
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        int count = 0;
        // time complexicity is (n*logn)
        while (!q.empty()) {

            // traverse all the levels
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                visited[temp] = 1;
                count++;
                for (auto adj_node : adj[temp]) {

                    if (visited[adj_node] != 1 && restrict[adj_node]==0) {
                          q.push(adj_node);
                    }
                }
            }
        }
        return count;
    }
};