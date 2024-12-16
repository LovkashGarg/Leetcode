class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
         int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        int i=0;
        while(i<k){
        
            auto temp=pq.top();
            pq.pop();
            int value=temp.first;
            int index=temp.second;
            nums[index]=value*multiplier;

            pq.push({value*multiplier,index});
            i++;
        }

        return nums;
    }
};