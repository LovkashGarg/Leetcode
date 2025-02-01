class Disjointset{

  
    public:
vector<int> parent;
vector<int> size;
vector<int>mini;
    Disjointset(){
        
    parent.resize(26);
    mini.resize(26);
    size.resize(26, 1);  // Each node initially has size 1
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
        mini[i]=i;
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

         mini[ulp_u]=min(mini[ulp_u],mini[ulp_v]);
         mini[ulp_v]= mini[ulp_u];
       
   
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjointset d;
        int n=s1.size();
        for(int i=0;i<n;i++){
            d.unionBysize(s1[i]-'a', s2[i]-'a');
        }

        string ans;
        
        for(int i=0;i<baseStr.size();i++){
            int c=baseStr[i]-'a';
        ans+=('a'+ d.mini[d.findPar(c)]);
        }
        return ans;
    }
};