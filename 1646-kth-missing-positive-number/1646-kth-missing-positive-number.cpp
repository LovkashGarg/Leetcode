class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int low=0;
        int high=arr.size()-1;
        int n=arr.size();

        int ans=0;
        int need=min(k,arr[0]-1);
        while(low<=high){
            int mid= (low+high)/2;
            int totalmissing= arr[mid]-mid-1; // means 3 elements missing 
            if(totalmissing <k){
                ans=arr[mid];
                need= k - totalmissing;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans+ need;


    }
};