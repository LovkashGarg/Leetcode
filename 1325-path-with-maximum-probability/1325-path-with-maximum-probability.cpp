class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> successProb_toPath(n,-1); // max probability is 1 
       vector<pair<double,int>>adj[n];
       successProb_toPath[start_node]=1;
        for(int j=0;j< edges.size();j++){
            adj[edges[j][0]].push_back({succProb[j],edges[j][1]});
            adj[edges[j][1]].push_back({succProb[j],edges[j][0]});
        }
        queue<pair<double,int>>pq;// where first is the probablility to the path
        // and second is the node name 
        pq.push({1,start_node});
        while(!pq.empty()){
            // I am trying to extract the node with max prob
            double prob=pq.front().first;
            int node=pq.front().second;
          cout<<node <<" "<<prob<<endl;
            pq.pop();
            
            for(auto j: adj[node]){
              double prob_of_edg=j.first;
              int adj_node=j.second;

              double newprob=prob_of_edg*prob;
              if(newprob >successProb_toPath[adj_node] ){
                successProb_toPath[adj_node]=newprob;
                pq.push({newprob,adj_node});
              }
            }
        }
        if(successProb_toPath[end_node]!=-1){
        return successProb_toPath[end_node];
        }
        return double(0);
    }
};