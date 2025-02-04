class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        // I want to find all the four length subarray
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {

                // I need to find the two element

                // my target to find the target - sum

                long long sum = nums[i] + 0ll + nums[j];
                long long newtarget = target - sum;
                int left = j + 1;
                int right = n - 1;
                while (left < right) {

                    if (newtarget == nums[left] + nums[right]) {
                        ans.insert({nums[i], nums[j], nums[left], nums[right]});
                        int val1 = nums[left];
                        int val2 = nums[right];
                        while (left < n && nums[left] == val1) {
                            left++;
                        }
                        while (right >= 0 && nums[right] == val2) {
                            right--;
                        }

                    } else if (newtarget > nums[left] + nums[right]) {
                        left++;
                    } else {
                        right--;
                    }
                }

                while (j + 1 < n && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }

    return vector<vector<int>>(ans.begin(), ans.end());
}
}
;