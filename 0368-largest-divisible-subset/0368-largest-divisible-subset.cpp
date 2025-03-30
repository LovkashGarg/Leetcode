class Solution {
public:
 
 int l_c_m(int a , int b){
    long long pro= 1ll* a*b;
    return pro/__gcd(a,b);
 }
int solve(int lcm  , int index , int n , vector<int>& nums){

    if(index==n){
        return 0;
    }

    // include 
    int include =0;
    if(lcm == 1 || nums[index] % lcm==0){
        int newlcm= l_c_m(lcm,nums[index]);
        include = 1+ solve(newlcm,index+1,n, nums);
    }
    int exclude = solve(lcm, index+1 ,n, nums);
    int ans= max(include , exclude);
    return ans;
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {

      int n=nums.size();

      vector<int>dp(n,1);
      vector<int>hash(n);
      sort(nums.begin(), nums.end());
      int maxlen=1;
      int last=0;

      for(int curr=1;curr<n;curr++){
        long long lcm=1;
        hash[curr]=curr;
        for(int prev=0;prev<curr;prev++){
            
     // if 8 is divisible by 4 then then 8 is always divisible by 2 
            if( nums[curr] % nums[prev]==0  && (1+ dp[prev]) > dp[curr]){
                // means increase the length 
               dp[curr]=max (1 + dp[prev], dp[curr]);
               hash[curr]=prev;
            }

        }
        if(dp[curr] >maxlen){
            maxlen= max(maxlen, dp[curr]);
            last=curr;
        }

      }

vector<int>ans;
      while(hash[last]!=last){
        ans.push_back(nums[last]);
        last= hash[last];
      }

       ans.push_back(nums[last]);
     reverse(ans.begin(), ans.end());
     return ans;
    
    }
};