class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        int n= rectangles.size();
        long long count=0;
        map<double,int>m;
        for(int i=0;i<n;i++){
           count +=m[double(rectangles[i][0])/ double(rectangles[i][1])];
            m[double(rectangles[i][0])/ double(rectangles[i][1])]++;
        }
        return count;
    }
};