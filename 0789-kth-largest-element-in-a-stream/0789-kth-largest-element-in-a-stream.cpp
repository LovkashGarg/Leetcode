class KthLargest {
public:
priority_queue<int>pq1;
priority_queue<int,vector<int>,greater<int>>pq2;
int k;

    KthLargest(int k, vector<int>& nums) {
        int i=0;
        // first priority queue stores only the highest element 
        for(int i=0;i<nums.size();i++){
          pq1.push(nums[i]);
        }
         this->k=k;
        while(!pq1.empty() && k--){
            // cout<<pq1.top()<<endl;
            pq2.push(pq1.top());
            pq1.pop();
        }

        //  while(!pq2.empty()){
        //     cout<<pq2.top()<<endl;
        //     pq2.pop();
        // }
        

    }
    
    int add(int val) {
        if(pq2.size()<k){
            pq2.push(val);
            return pq2.top();
        }
        if(pq2.top() >=val){
            // nothing to worrry 
            return pq2.top();
        }
        else{
         pq2.pop();
         pq2.push(val);
         return pq2.top();
        }
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */