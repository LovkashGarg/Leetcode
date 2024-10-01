class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int num=i;
            int count=0;
            for(int j=0;j<=31;j++){
              int d=(num>>(31-j))%2;
            //   cout<<d<<endl;
              if(d==1){
               count ++;
              }
            }
            ans.push_back(count);
        }
        return ans;
    }
};