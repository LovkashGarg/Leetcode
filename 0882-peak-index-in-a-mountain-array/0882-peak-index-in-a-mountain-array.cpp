class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int low=0;
        int n= arr.size();
        int high= n-1;
        int ans=n;
        while(low<high){
            int mid= (low+high)/2;
           if(arr[mid] >arr[mid+1]){
             ans= mid;
             high= mid;
           }
           else{
            low=mid+1;
           }
        }

        return ans;
        
    }
};