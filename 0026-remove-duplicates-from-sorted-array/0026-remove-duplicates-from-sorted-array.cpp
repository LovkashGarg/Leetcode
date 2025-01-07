class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

      unordered_set<int>s;
      vector<int>orderd;
      for(auto i:nums){
         if(s.find(i) ==s.end()){
            s.insert(i);
            orderd.push_back(i);
         }
      }

      for(auto i=0;i<orderd.size();i++){
        nums[i]=orderd[i];
      }
      return s.size();
    }
};