class Solution {
public:
int mod=1e9+7;
   vector<int> nextsmallerele(vector<int>&arr){
    int n=arr.size();
    stack<int>s;
    vector<int>nse(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            nse[i]=n;
        }
        else{
            nse[i]=s.top();
        }

        s.push(i);
    }

    return nse;
   }
   vector<int> previousmaller_or_equal(vector<int>&arr){
        int n=arr.size();
        vector<int>pse(n);
        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=s.top();
            }
            s.push(i);

        }
        return pse;
   }
    int sumSubarrayMins(vector<int>& arr) {

        int n=arr.size();
        vector<int>nse(n);
        nse=nextsmallerele(arr);
        vector<int>pse(n);
        pse=previousmaller_or_equal(arr);
        
       long int totalsum=0;
        for(int i=0;i<n;i++){
        int left=i-pse[i]; // this would tell how many contributions it would have on left 
        int right=nse[i]-i; // this would tell how many times it would be included 
        // for ex for 1 next nse =4 means no one 
        // right=4-1 =3 means for all the subarray with this 3 elements It would have the min to be 1 
        // left = 1-(-1) means for all the subarray with this 2 elements it would be the answer 
        // total subarry =left*right with this index 
        totalsum = (totalsum + ((left*right *1ll*arr[i])%mod))%mod;
        }
        return totalsum;
    }
};