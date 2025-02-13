class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
      int count=0;
      int n=nums.size();
      map<int,int>m; 
      sort(nums.begin(),nums.end());
      m[nums[0]]=1;
      for(int i=1;i<n;i++){
        // here if it already exist 
        if(m.find(nums[i])!=m.end()){
         int last=nums[i];
          m[nums[i-1]+1]=1;
          nums[i]=nums[i-1]+1;
         count+= (nums[i-1]+1- last);
        }
        else{
            m[nums[i]]=1;
        }
      } 
      return count;
    }
};