class Solution {
public:
    int triangleNumber(vector<int>& arr) {

       sort(arr.begin(),arr.end());
       int n=arr.size();
       long long finalans=0;
       for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
          
          int low= j+1;
          int high=n-1;
          int ans=0;
          while(low<=high){
            int mid= (low+high)/2;
            if(arr[i]+arr[j] >arr[mid]){
                ans=mid-j;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
          }
        finalans+=ans;
        }

       } 

       return finalans;
    }
};