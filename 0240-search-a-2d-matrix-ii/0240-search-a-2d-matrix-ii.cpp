class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowrow=0;
        int highrow=matrix.size()-1;

        for(int midrow=0;midrow<matrix.size();midrow++){

            int lowcol=0;
            int highcol=matrix[0].size()-1;
            if(matrix[midrow][lowcol]<=target && target <= matrix[midrow][highcol]){
                while(lowcol<=highcol){
                    int midcol=(lowcol+ highcol)/2;
                    if(matrix[midrow][midcol]==target){
                        return true;
                    }
                    else if(matrix[midrow][midcol] <target){
                        lowcol=midcol+1;
                    }
                    else{
                         highcol=midcol-1;
                    }
                } 
            }
        }
        return false;
    }
};