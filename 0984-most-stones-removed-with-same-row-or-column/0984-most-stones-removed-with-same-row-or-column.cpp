class Disjoint_set{
public:
    vector<int>rank,parent;
    vector<int>size;
Disjoint_set(int n){
    // rank.resize(n+1,0);
    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}
int findPar(int node){
    if(node==parent[node]){
        return node;
    }
    else{
        // assignment makes it in constant time else it is 
        // log(n)
        return parent[node]=findPar(parent[node]);
    }
}
void unionBysize(int u,int v){
    int ulp_u=findPar(u);
    int ulp_v=findPar(v);

    if(ulp_u==ulp_v)  return;
    if(size[ulp_u] < size[ulp_v]){
   parent[ulp_u]=ulp_v;
   size[ulp_v]+=size[ulp_u];
    }
    else {
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        //for each coordinate I have to see how many coordinates are in same row and same column 

        // if same row then mark them as connected and make their parent same 
 int n=stones.size(); // no of stones
Disjoint_set ds(n);
// vector<vector<int>>adj(n);
// first  tell which element are connected 

        for(int i=0;i<n;i++){
            int row=stones[i][0];
            int col=stones[i][1];
            for(int j=0;j<n;j++){
                int stonerow=stones[j][0];
                int stonecol=stones[j][1];

                if(row == stonerow || col==stonecol && i!=j){
                //   adj[i].push_back(j); 
                  ds.unionBysize(i,j);
                }
            }
        }
     unordered_map<int,int>m;
        // Now check all the clusters now since elements from each cluster can be removed and only one element can be left 
         for(int i=0;i<n;i++){
            m[ds.findPar(i)]++;
         }
         int ans=0;
         for(auto ele:m){
            // means stone can be removed
            if(ele.second>1){
              ans +=(ele.second -1);
            }
         }
         return ans;
    }
};