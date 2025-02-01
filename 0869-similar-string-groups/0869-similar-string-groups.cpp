class Disjointset{
    public:
    vector<int>parent;
    vector<int>size;
    Disjointset(int n){
       parent.resize(n);
       size.resize(n);
       for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
       }
    }

    int findPar(int node){
        if(node== parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);

    }

    void unionBysize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u!=ulp_v){
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
int n=strs.size();
        Disjointset d(n);


        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               
               // now here we check for 
               int change=0;

               for(int k=0;k<strs[i].size();k++){
                if(strs[i][k] != strs[j][k]){
                    change++;
                }
               }

               if(change <=2){
                d.unionBysize(i,j);
               }

            }
        }

     set<int>s;
     
     for(int i=0;i<n;i++){
        s.insert(d.findPar(i));
     }

     return s.size();
    
    }
};