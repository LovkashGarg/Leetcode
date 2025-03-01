class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1] ) {
                nums[i] = ( nums[i]*2);
                nums[i + 1] = 0;
            }
        }
         vector<int>nonzero;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
nonzero.push_back(nums[i]);
            }
        }
        cout<<endl;


        for(int i=0;i<nonzero.size();i++){
            nums[i]=nonzero[i];
        }

        for(int i=nonzero.size();i<n;i++){
            nums[i]=0;
        }
        return nums;
    }
};