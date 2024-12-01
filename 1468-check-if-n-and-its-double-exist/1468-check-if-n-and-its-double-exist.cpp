class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        // for negative elements 
        int d=0;
        for(int i=0;i<n;i++){
            if(arr[i] >0){
                d=i;
                break;
            }
        }
    //    cout<<d<<endl;
       for(int i=d-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
             if(arr[i]*2==arr[j]){
                    return true;
             }
          }
       }



        for(int i=d;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]*2==arr[j]){
                    return true;
                }
            }
        }

        return false;
    }
};