class Disjointset{

  
    public:
vector<int> parent;
vector<int> size;
    Disjointset(){
        
    parent.resize(26);
    size.resize(26, 1);  // Each node initially has size 1
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }
    }

    int findPar(int node){
         if(node== parent[node]){
            return node;
         }
         else{
            return parent[node]= findPar(parent[node]);
         }
    }

    void unionBysize(int u,int v){

        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u== ulp_v){
            return ;
        }

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
    bool equationsPossible(vector<string>& equations) {
        Disjointset d;
        int n=equations.size();
        for(int i=0;i<n;i++){
         if(equations[i][1]=='='){
               int a=equations[i][0]-'a';
              int b=equations[i][3]-'a';
            d.unionBysize(a , b);
         }
        
        }

        vector<int>temp=d.parent;
        // for(int i=0;i<temp.size(); i++){
        //     cout<<temp[i]<<" "; 
        // }
        // cout<<endl;
        
        for(int i=0;i<n;i++){
              int a=equations[i][0]-'a';
              int b=equations[i][3]-'a';
              int ulp_u= d.findPar(a);
              int ulp_v=d.findPar(b);
           if(equations[i][1]=='='){
           
// then they should have same parent 
              if(ulp_u!=ulp_v){
                return false;
              }
           }
           else{
                if(ulp_u == ulp_v){
                    return false;
                }
           }
        }

        return true;





    }
};