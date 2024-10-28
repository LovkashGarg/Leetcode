class Solution {
    int count = 0;

public:
    void merge(int low, int mid, int high, vector<int>& nums, int n) {

        int rightindex = mid + 1;
        for (int i = low; i <= mid; i++) {
            for (; rightindex <= high; rightindex++) {
                if (nums[i] <= (long(2) * (nums[rightindex]))) {
                    break;
                }
            }
            count += (rightindex - mid - 1);
        }

        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {

            // problem comes when 1 ,2, 3 and 1,3 array
            // since here first condition is left goes
            // then pointer at 2 and 1 since 2 is greater therefor right ++
            // therefore our 3,1 case misses
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        // now I have two sorted arrays
        // now since the number that satisfy previous would always satisfy the
        // next elements time complexicty is o(mid-low)+ o(high-mid)

        // ... rest of the merge function ...
    }
    void mergesort(int low, int high, vector<int>& nums, int n) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergesort(low, mid, nums, n);
            mergesort(mid + 1, high, nums, n);
            merge(low, mid, high, nums, n);
        }
    }
    int reversePairs(vector<int>& nums) {
     
        int n = nums.size();
        mergesort(0, n - 1, nums, n);
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return count;
    }
};