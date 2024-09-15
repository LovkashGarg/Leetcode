class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int high=(n*m)-1;

        while(low<=high){
            int mid=(low+ high)/2;

            int rowindex=mid/m; // converting to 2 D element point 
            int colindex=mid%m;
            if(matrix[rowindex][colindex]==target){
                return true;
            }
            else if(matrix[rowindex][colindex]<target){
               low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};