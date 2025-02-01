///Disjoint set snippet code
class Disjointset {
   
public:
 //constructor
  vector<int> rank, parent, size;
    Disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
///find ultimate parent function
    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;//both belong to same compo as both have same ultimateparent
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {//same rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;//both belong to same compo as both have same ultimateparent
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        // here first find the distance between each pair of vertices 
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
            
        // calculate manhattan distance 
            int total= abs(points[i][0]- points[j][0])+ abs(points[i][1]- points[j][1]);
            edges.push_back({total,{i,j}});
            }
        }

       Disjointset d(n);
        sort(edges.begin(),edges.end());
        int m=edges.size();
        long long totalcost=0;
        for(int i=0;i<m;i++){
            // now here 
            int ulp_u=d.findUpar(edges[i].second.first);
            int ulp_v=d.findUpar(edges[i].second.second);

// different component we can join 
            if(ulp_u!= ulp_v){
              totalcost+=(edges[i].first);
              d.unionbysize(edges[i].second.first, edges[i].second.second);
            }
        }
        return totalcost;

    }
};