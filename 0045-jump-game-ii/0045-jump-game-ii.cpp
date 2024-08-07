class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int count = 0;
        if(n==1){
            return 0;
        }
        
        while (i < n) {
            if(nums[i] ==0){
              return -1;
        }
            if (nums[i] + i >= n - 1) {
                count++;
                break;
            }
            int maxi = 0;
            int k = 0;
            int maxindex = 0;
            for (int j = nums[i] + i; j >= (i + 1) && j < n; j--) {
                if (maxi < nums[j] - k) {
                    // cout << "jump" << nums[j] - k << endl;
                    maxi = max(maxi, nums[j] - k);
                    maxindex = j;
                }
                k++;
            }
            cout << "maxindex " << maxindex << endl;
            // cout << maxi << endl;
            if(maxi==0){
                return -1;
            }
            i = maxindex;
            count++;
        }
        return count;
    }
};