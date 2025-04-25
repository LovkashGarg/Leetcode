class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        long long count=0;
        long long equals=0;
        unordered_map<int,int>m;

        m[0]=1;

        for(auto &i:nums){

            // here we update equal when we got a element with the condition 
            if(i%modulo==k) equals++;

            int rem=equals%modulo;
            int needed= (rem-k + modulo) %modulo;
            count+= m[needed]; // zChecking how much element are available with this value before
            m[rem]++;
        }  

         return count;
    }
};