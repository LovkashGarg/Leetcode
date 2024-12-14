class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l = 0; // Left pointer for the window
        int r = 0; // Right pointer for the window
        long long count = 0;

        deque<int> minDeque; // To maintain minimums
        deque<int> maxDeque; // To maintain maximums

        while (r < nums.size()) {

            // Maintain minDeque for minimum values
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(r);

            // Maintain maxDeque for maximum values
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);


            // Check the condition for the window jab tak na ho 
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                l++; // window shrink kar dijiye 
                if (minDeque.front() < l) minDeque.pop_front();
                if (maxDeque.front() < l) maxDeque.pop_front();
            }
            
            // most important line 
            count += (r - l + 1);
            cout<< r<< l<< count<<endl;
            r++; 
        }
        return count;
    }
};
