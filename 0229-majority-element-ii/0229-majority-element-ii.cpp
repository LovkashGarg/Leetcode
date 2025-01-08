class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // here only two element possible with freq
        int ele1=INT_MAX;
        int ele2=INT_MAX;
        int count1=0;
        int count2=0;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ele1== nums[i]){
                count1++;
            }
            else if(ele2==nums[i]){
                  count2++;
            }
            else if(count1==0 ){
              count1=1;
              ele1=nums[i];
            }
            else if(count2==0){
              count2=1;
              ele2=nums[i];
            }
            else {
                count1--;
                count2--;
            }

            
        }

        count1=0;
        count2=0;
       vector<int>ans;
        // now check for number of count of 
        for(int i=0;i<n;i++){
            if(ele1== nums[i]){
                count1++;
            }
            else if(ele2== nums[i]){
                count2++;
            }
        }
 
        if(count1 >(n/3)){
           ans.push_back(ele1);
        }


        if(count2 >(n/3)){
         ans.push_back(ele2);
        }
        return ans;

    }
};