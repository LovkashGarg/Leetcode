class Disjoint_set {
public:
    vector<int> parent;
    vector<int> size;
    Disjoint_set(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <=n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(parent[node]==node){
            return node;
        }
        else{
            return parent[node]=findPar(parent[node]);
        }
    }
    void unionBysize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u] <size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
      }

};
 class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n=edges.size();
        Disjoint_set ds(n);
        vector<int>ans;
        for(int i=0;i< n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            cout<<i<<endl;
            if(ds.findPar(u) != ds.findPar(v)){
                ds.unionBysize(u,v);
            }
            else{
                ans=edges[i];
            }
        }
        return ans;
    }
};