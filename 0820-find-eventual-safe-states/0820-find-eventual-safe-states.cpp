class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adjRev[V];
        vector<int>indegree(V,0);
        for (int i = 0; i < graph.size(); i++) {
            // i--> it
            // it--> i
            for (auto adj_node : graph[i]) {
                adjRev[adj_node].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
q.push(i);
            }
        }vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto adj_node: adjRev[node]){
                 indegree[adj_node]--;
                 if(indegree[adj_node]==0){
                    q.push(adj_node);
                 }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};