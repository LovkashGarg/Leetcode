class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        multiset<int> s;
        int n = nums.size();
        for (int i = 0; i < k - 1; i++) {
            s.insert(nums[i]);
        }

        vector<int> ans;
        // time complexicity is 0(k*logk)
        for (int i = k - 1; i < n; i++) {
            s.insert(nums[i]);
            ans.push_back(*s.rbegin());
           
            auto it = s.find(nums[i - k + 1]); // it returns the first occurence
                                               // of nums[i-k+1]
            if (it != s.end()) {
                s.erase(it);
            }
        }

        return ans;
    }
};