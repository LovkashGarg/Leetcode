class Solution {
public:
    vector<int> previous_smaller_or_equal(vector<int>&nums){
        int n=nums.size();
        vector<int>pse(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()] >nums[i]){
                s.pop();
            }

            if(s.empty()){
            pse[i]=-1;
            }
            else{
                pse[i]=s.top();
            }
            s.push(i);
        }
        return pse;
    }

    vector<int> previous_greater_or_equal(vector<int>&nums){
        int n=nums.size();
        stack<int>s;
        vector<int>pge(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                s.pop();
            }

            if(s.empty()){
                pge[i]=-1;
            }
            else{
pge[i]=s.top();
            }
            s.push(i);
        }
        return pge;
    }

    vector<int> next_greater_element(vector<int> &nums){
        int n=nums.size();
        stack<int>s;
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] <= nums[i]){
                s.pop();
            }

            if(s.empty()){
                nge[i]=n;
            }
            else{
                nge[i]=s.top();
            }
            s.push(i);
        }
        return nge;
    }

      vector<int> next_smaller_element(vector<int> &nums){
        int n=nums.size();
        stack<int>s;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }

            if(s.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=s.top();
            }
            s.push(i);
        }
        return nse;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long int mintotalsum=0;
        long long int maxtotalsum=0;

        vector<int>nse(n);
        vector<int>nge(n);
        vector<int>pge(n);
        vector<int>pse(n);
        nse=next_smaller_element(nums);
        nge=next_greater_element(nums);

        pse=previous_smaller_or_equal(nums);
        pge=previous_greater_or_equal(nums);

        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            mintotalsum= mintotalsum + (left*right*1ll* nums[i]);
        }
        for(int i=0;i<n;i++){

            int left=i-pge[i];
            int right=nge[i]-i;
            maxtotalsum= maxtotalsum + (left*right*1ll* nums[i]);
        }
        
        return maxtotalsum -mintotalsum;

    }
};