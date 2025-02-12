class Solution {
public:
int rev(int n)   //function to find reverse of a number
    {
        int res=0;
        while(n!=0)
        {
            res=res*10+n%10;
            n/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        
        int n= nums.size();
        unordered_map<int,int> m;
        int mod=1e9 +7;
        long count=0;
        
        for(int i=0;i<n;i++){
            // find the reverse
            int newnum= rev(nums[i]);      
            count=( count+ m[nums[i]- newnum])%mod;
            m[nums[i]-newnum]++;

        }


        return count;

    }
};