class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

       map< double, pair<int,int>  > m;
       int n=arr.size();
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m[double (arr[i]) / double(arr[j])   ]={arr[i],arr[j]};
        }
       }
       int count=0;

       for(auto i:m){
         count++;
         if(count==k){
            return {i.second.first, i.second.second};
         }
       }
       return {};
    }
};