class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int total=0;
        for(int i=0;i<n;i++){
          int low=0;
          int high=m-1;
          int number=0;
          while(low<=high){
            int mid= (low)+ (high-low)/2;
            if(grid[i][mid] <0){
                number=m-mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
          }
          total+=number;
        }
        return total;
    }
};