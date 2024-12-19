class Solution {
public:
    int trap(vector<int>& heights) {
int n=heights.size();
    vector<int>prefixMax(n);
    vector<int>suffixMax(n);
    prefixMax[0]=heights[0]; // stores max till i th index 

    for(int i=1;i<n;i++){
        prefixMax[i]=max(prefixMax[i-1],heights[i]);
    }

    suffixMax[n-1]=heights[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1],heights[i]);
    }

    // now water will be trapped on the rooftop  if we have two buildings on left and right 
    int totalwater=0;
    for(int i=0;i<n;i++){
      if(heights[i] < prefixMax[i] && heights[i] <suffixMax[i]){
        totalwater+=((min(prefixMax[i],suffixMax[i])-heights[i]));
      }
    }
    return totalwater;
    }
};