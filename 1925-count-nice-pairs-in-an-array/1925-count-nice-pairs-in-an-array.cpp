class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        int n= nums.size();
        unordered_map<int,int> m;
        int mod=1e9 +7;
        long count=0;
        
        for(int i=0;i<n;i++){
            // find the reverse 
            int newnum=nums[i];

            if(nums[i] >=10){
            string num=to_string(nums[i]);
            reverse(num.begin(),num.end());
            // remove leading zeroes
            int j=0;
            while(num[j] == 0 && j<num.size()){
                j++;
            }
             num= num.substr(j);
            newnum=stoi(num);
            }
            else{
                newnum=nums[i];
            }
            
            count=( count+ m[nums[i]- newnum])%mod;
            m[nums[i]-newnum]++;

        }

        return count;

    }
};