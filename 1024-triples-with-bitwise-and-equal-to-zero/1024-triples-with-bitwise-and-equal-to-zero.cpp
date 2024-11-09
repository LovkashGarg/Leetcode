class Solution {
public:
    int countTriplets(vector<int>& nums) {
unordered_map<int,int>m;

int n=nums.size();
// time complexicity is O(n2)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[nums[i]&nums[j]]++;
            }
        }
        
        int count=0;


        for(int i=0;i<n;i++){
            for(auto j:m){
             if(   ((j.first &nums[i])==0)    ){
                    count+=j.second;
              }
            }
        }
        
        return count;
    }
};