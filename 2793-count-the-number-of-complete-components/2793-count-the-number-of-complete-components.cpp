class Solution {
public:
 void solve(int node , vector<int> &visited, vector<vector<int>> &adj, int n,   map<int,unordered_set<int>>&s,int comp){

    visited[node]=1;
     s[comp].insert(node);
    for(auto adj_node:adj[node]){
        if(!visited[adj_node]){
            solve(adj_node,visited,adj, n, s,comp);
        }
    }

 }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        map<int,unordered_set<int>>s;
        int d=edges.size();
        vector<vector<int>> adj(n);

       for(auto &i:edges){
             adj[i[0]].push_back(i[1]);
             adj[i[1]].push_back(i[0]);
       }

      int comp=0;
      vector<int>visited(n,0);
       map<int,int>m2;
       for(int i=0;i<n;i++){
            if(!visited[i]){
                solve(i,visited,adj,n,s,comp);
                comp++;
                // m2[comp]=0; // there are 0 edges for sure 
            }
       }

     
      for(auto &i:edges){
            for(auto &m:s){
              if(m.second.find(i[0])!=m.second.end()){
                m2[m.first]++;
              }
            }
      }

int count=0;
     for(auto &i:s){
         int nodes= i.second.size();
         int edges= m2[i.first];
         int total= nodes*(nodes-1)/2;
         if(total == edges){
            count++;
         }


     }


      return count;

    }
};