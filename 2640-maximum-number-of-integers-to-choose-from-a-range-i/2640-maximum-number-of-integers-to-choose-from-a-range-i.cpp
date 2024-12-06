class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int>present(10001);
        for(int i=0;i<banned.size();i++){
            present[banned[i]]=1;
        }

        int sum=0;
        int count=0;
        for(int i=1;i<=n;i++){
            // matlab ki yeh element present hai ya nhi 
            if(present[i]==0){
              sum+=i;
              if(maxSum<sum){
                break;
              }
              count++;
            }
        }
        return count;
    }
};