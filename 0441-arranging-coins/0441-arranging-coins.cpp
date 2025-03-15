class Solution {
public:
    int arrangeCoins(int n) {
        
      long long total =0;
      cout<<INT_MAX<<endl;
      for(int i=1;i<=n;i++){
        total+=i;
        if(total >n){
            return i-1;
        }
        else if(total==n){
            return i;
        }
      }
      return -1;

    }
};