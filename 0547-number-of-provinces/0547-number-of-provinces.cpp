class Disjoint_set{
    public:
    vector<int> parent;
    vector<int> size;

    Disjoint_set(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        else{
            return parent[node]=findPar(parent[node]);
        }
    }
    void unionBysize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u == ulp_v){
            return;
        }
        else{
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+= size[ulp_u];
            }
            else{
                  parent[ulp_v]=ulp_u;
                  size[ulp_u]+= size[ulp_v];
            }
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
    //   Disjoint_set ds(isConnected.size());
    //   vector<vector<int>>adj(n,{});
      int n=isConnected.size();

      Disjoint_set ds(n);

     for(int i=0;i< n;i++){
        for(int j=0;j<n;j++){
           if(isConnected[i][j]==1){
            ds.unionBysize(i,j); // connect all the componnents 
           }
        }
     }
     int d=0;
     for(int i=0;i<n;i++){
        // cout<<ds.parent[i]<<endl;
        if(ds.parent[i]==i){
            d++;
        }
     }
     return d;
    }
};