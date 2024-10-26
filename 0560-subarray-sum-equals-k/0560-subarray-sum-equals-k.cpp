class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int cnt=0;
        int prefix=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          prefix+=nums[i];

          int remove=prefix-k;
          cnt+=m[remove];
          m[prefix]++;
        }
        return cnt;
        }
};