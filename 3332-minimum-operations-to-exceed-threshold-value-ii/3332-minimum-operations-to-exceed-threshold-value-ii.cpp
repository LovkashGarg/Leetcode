class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long,vector<long long>, greater<long long>>pq;

        int n= nums.size();
        for(int i=0;i<n;i++){
pq.push(nums[i]);
        }
        
       int i=0;
        while(pq.size() >=2){
        long long first=pq.top();
        pq.pop();
        long long second=pq.top();
        pq.pop();
        if(first >=k){
            return i;
        }

        long long val= first*2 + second;
        pq.push(val);
        i++;
        }

        return i;

    }
};