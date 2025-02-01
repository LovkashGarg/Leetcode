
// class Disjointset{

//     public:
//     vector<int> parent{26, 0};
//     vector<int>size{26,0};
//     Disjointset(){
//      for(int i=0;i<26;i++){
//            parent[i]=i;
//      }

//     }

//     int findPar(int node){
//          if(node== parent[node]){
//             return node;
//          }
//          else{
//             return parent[node]= findPar(parent[node]);
//          }
//     }

//     void unionBysize(int u,int v){

//         int ulp_u=findPar(u);
//         int ulp_v=findPar(v);

//         if(ulp_u== ulp_v){
//             return ;
//         }

//         if(size[ulp_u] < size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else {
//              parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }

//     }

// };

class Solution {
public:
   
    vector < vector<pair<char, int>>> comp;
    void dfs(int index, string &s, vector<pair<char, int>>& output,
             vector<vector<int>>& adj,vector<int>&visited ) {
        visited[index] = 1;
        output.push_back({s[index], index});

        for (auto adj_node : adj[index]) {
            if (!visited[adj_node]) {
                dfs(adj_node, s, output, adj,visited);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = pairs.size();
        int m = s.size();
        vector<vector<int>> adj(m);
        for (int i = 0; i < n; i++) {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }

        vector<int> visited(m, 0);
        for (int i = 0; i < m; i++) {
            vector<pair<char, int>> output;
            if (!visited[i]) {
                dfs(i, s, output, adj,visited);
                comp.push_back(output);
            }
        }

        // time complexicity is O((n + e)  + o(n*log(n)) )

        for(int i=0;i<comp.size();i++){
            vector<char>temp1;
            vector<int>temp2;
            for(int j=0;j<comp[i].size();j++){
                temp1.push_back(comp[i][j].first);
                temp2.push_back(comp[i][j].second);
            }
            sort(temp1.begin(),temp1.end());
            sort(temp2.begin(),temp2.end());

            for(int i=0;i<temp1.size();i++){
               s[temp2[i]]= temp1[i];
            }
          
        }

        return s;

    }
};