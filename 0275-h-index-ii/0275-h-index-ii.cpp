class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int low=0;
        int n= citations.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
 maxi=max(maxi, citations[i]);
        }
        int high=maxi;

        // this is the max possible answer 
        int ans=0;
        while(low<=high){
            int mid= (low+high)/2;
            int lower= lower_bound(citations.begin(),citations.end(),mid)-citations.begin();
            int totalgreater_equal= n-lower;
              
              // this is a possible ans 
            if(totalgreater_equal>=mid){
              ans=mid;
              low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};