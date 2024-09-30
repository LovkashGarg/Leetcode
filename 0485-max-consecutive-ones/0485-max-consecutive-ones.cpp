class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int i=0;
      int maxlen=0;
      while(i< nums.size()){
        if(nums[i]==1){
            int j=i+1;
            while(j< nums.size() && nums[j]==1){
                j++;
            }
            int len= j-i;
            maxlen=max(maxlen,len);
            i=j;
        }
        else{
            i++;
        }
      }
      return maxlen;
    }
};