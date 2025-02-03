class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> levelneed(m,vector<int>(n,1e6));

        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>> > > pq;
        pq.push({grid[0][0],{0,0}}); // since starting hai to itna to lgega
vector<int>dirrow={0,1,0,-1};
vector<int>dircol={1,0,-1,0};
levelneed[0][0]= grid[0][0];

        while(!pq.empty()){
            auto temp=pq.top();
            int level= temp.first; // till now level need to swim 
            int x=temp.second.first;
            int y=temp.second.second;
            pq.pop();


           for(int k=0;k<4;k++){
            int newrow= x+ dirrow[k];
            int newcol=y+ dircol[k]; 
            if(newrow>=0 && newcol >=0 && newrow < m && newcol < n){
               int newval= max(level,grid[newrow][newcol]);
               
               if(newval < levelneed[newrow][newcol]){
                levelneed[newrow][newcol]= min(newval, levelneed[newrow][newcol]);
                pq.push({levelneed[newrow][newcol],{newrow,newcol}});
               }

            }
            
           }
        }

        return levelneed[m-1][n-1];
    }
};