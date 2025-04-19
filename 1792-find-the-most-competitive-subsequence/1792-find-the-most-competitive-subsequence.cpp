class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n = nums.size();
        stack<int>s;
        // for(int i=0;i<k;i++){
        //     s.push(i);
        // }
          
        for(int i=0;i<n;i++){
        
          // see if this element is smaller then the previous subsequence end then why not take him 
          // but I can afford to remove only certain number of elements 
          // s.size() 
          //-1 for the ele to be removed 
          // +1 element to be pushed 
          // left elements after the current index 
          while(!s.empty() && (s.size()-1+1 +(n-i-1 )>=k)  && nums[s.top()] > nums[i]){
            s.pop();
          }

          // matlab ham bas apne kam ka samman rakhenge
          if(s.size()==k){
            continue;
          }
          else{
          s.push(i);
          }
          
        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(nums[s.top()]);
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};