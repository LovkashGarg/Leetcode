class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        int n = nums.size();
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        vector<bool> prime(maxi + 1, true);

        for (int p = 2; p * p <= maxi; p++) {
            if (prime[p] == true) {
                // Update all multiples of p greater than or equal
                for (int i = p * p; i <= maxi; i += p)
                    prime[i] = false;
            }
        }
       

    //    for(int i=2;i<=maxi;i++){
    //     cout<<i<<" "<<prime[i]<<endl;
    //    }
    //    cout<<endl;


        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                continue;
            } else {
                // I have to subtract it with the least posible
                // which makes it greater then
                // choose one prime number if it makes our number just less than
                // the next number

                for (int j = 2; j < nums[i]; j++) {
                    if (prime[j ] && nums[i] - j < nums[i + 1]) {
                        // cout << "PRIME " << j << " " << i << endl;
                        nums[i] = nums[i] - j;
                        break;
                    }
                }
            }
        }

      bool flag=true;
       for(int i=0;i<n-1;i++){
        if(nums[i] >=nums[i+1]){
         flag=false;
        }
       }
        return flag;
    }
};