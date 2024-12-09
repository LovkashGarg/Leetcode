class NumArray {
public:
    vector<int>prefix;
    vector<int>arr;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
             prefix.push_back(sum);
             arr.push_back(nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right]-prefix[left]+ arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */