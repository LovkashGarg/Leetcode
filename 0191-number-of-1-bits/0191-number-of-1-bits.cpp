class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        for(int i=1;i<=32;i++){
          int d=(n>>(32-i))%2;
          if(d){
            count++;
          }
        }
        return count;
    }
};