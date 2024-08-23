class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low)+ (high-low)/2;
            if(arr[mid]==target){
                return mid;
            }
            // identify the sorted half 
          // left sorted 
            else if(arr[low] <=arr[mid] ) {
              // check if the target present in between 
            
                if(arr[low]<=target && target <arr[mid]){
                     high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //  right part is sorted 
            else {
                  // check if the element is present or not
                  if(arr[mid]<target&& target <= arr[high]){
                   low=mid+1;
                  }
                  else{
                    high=mid-1;
                  }
            }
        }
        return -1;

    }
};