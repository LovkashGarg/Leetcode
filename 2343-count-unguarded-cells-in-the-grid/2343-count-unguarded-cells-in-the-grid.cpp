class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>>grid(m,vector<int>(n,0));

        // cout<<guards.size()<<endl;
        // return 1;

        // 
         for(auto i: guards){
            // make 
            grid[i[0]][i[1]]=2;
         }

          for(auto i: walls){
            grid[i[0]][i[1]]=-1;
          }

          // time complexicity is 0( guardlen * (max(m,n))) which cant run 10^9
         for(auto ele : guards){

        // make it one for all the elements

           // all four directions
           int rowx=ele[0];
           int rowy=ele[1];
           for(int i=rowx+1;i<m;i++ ){

            if(grid[i][rowy]==-1 || grid[i][rowy]==2){
             break;
            }

            grid[i][rowy]=1;
              
           }

            for(int i=rowx-1;i>=0;i-- ){
            if(grid[i][rowy]==-1 || grid[i][rowy]==2){
             break;
            }
            grid[i][rowy]=1;
             }

            for(int i=rowy+1;i<n;i++ ){
            if(grid[rowx][i]==-1 || grid[rowx][i]==2){
             break;
            }
            grid[rowx][i]=1;
            }

            for(int i=rowy-1;i>=0;i--){
              if(grid[rowx][i]==-1 || grid[rowx][i]==2){
             break;
            }
            grid[rowx][i]=1;  
            }

         }
         int count=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
         }
        return count;
         
    }
};