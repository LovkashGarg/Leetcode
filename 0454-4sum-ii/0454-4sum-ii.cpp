class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        map<long long,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            mp[nums4[i] +0ll+ nums3[j]]++;
        }
        } 
        
int total=0;
        for(auto i: nums1){
            for(auto j: nums2){
           
                    long long newtarget=-(i+j);
total+=mp[newtarget];
            }
        }
        return total;
    }
};