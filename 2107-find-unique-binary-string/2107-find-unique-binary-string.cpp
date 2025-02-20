class Solution {
public:

  unordered_set<string>ans;
    void solve(int index,int n, string &s){
        if(index>=n){
            ans.insert(s);
            return ;
        }
        s.push_back('0');
        solve(index+1, n,s);
        s.pop_back();

         s.push_back('1');
        solve(index+1, n,s);
        s.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
      
        string s;
        int index=0;
        solve(index,n,s);
        sort(nums.begin(),nums.end());
       for(auto i:ans){

         if(find(nums.begin(), nums.end(), i) ==nums.end()){
            return i;
         }

       }
      
       return "";
    }
};