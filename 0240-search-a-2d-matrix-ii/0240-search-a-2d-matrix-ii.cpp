class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int row=0;
      int col= matrix[0].size()-1;
int n=matrix.size();
int m=matrix[0].size();


      while( row < n && col >=0 ){
        // cout<< row<< " "<<col<<endl;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col] <target){
                 row=row+1;
            }
            else{
                col =col-1;
            }
      }
      return false;
    }
};