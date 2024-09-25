class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    
       stack<int> s;
       int n=nums.size();
       vector<int> ans (n,-1);
       for(int i=n-1;i>=0;i--){
        bool flag=true;
        if(!s.empty())
        // cout<<s.top()<<" "<<i<<endl;
        while(!s.empty() && nums[s.top()]<=nums[i]){
            s.pop();
        }
       
        if(!s.empty()){
            ans[i]=nums[s.top()];
        }
        else{
        
            for(int j=0;j< i;j++){
                if(nums[j] >nums[i]){
                ans[i]=nums[j];
                s.push(j);
                s.push(i);
                flag=false;
                break;
                }
            }
        }
        if(flag==true)
         s.push(i);
       }
       return ans;
    }
};