class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // I can use a monotonic queue 
        // brute force 
        int n=nums.size();
          vector<int>ans;
         deque<int>dq;
         for(int i=0;i<n;i++){

          // first I need to check if there is some element which should be retarded since 
          // the window size is being crossed
          // dq.front() // means the last element 

// eg for window size k=3 we are i=3 and dq.front()= 0  means 0 should be retarded 
          if(!dq.empty()  && (i-dq.front() >=k) )  {
            dq.pop_front(); // remove the last element 
          }


         // maintain a stack of monotonic decreasing nature 
         while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back(); // I need to maintain a order 
         }


          dq.push_back(i);

          // now how is answer we got 
          // last element is the answer 
          if(i>=k-1){
            ans.push_back(nums[dq.front()]);
          }
          
         }
         return ans;

        

    }
};