class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        set<int>ans1;
        for(int i=0;i<nums2.size();i++){
           if(s1.find(nums2[i])==s1.end() ){
             ans1.insert(nums2[i]);
           }
        }

        unordered_set<int>s2(nums2.begin(),nums2.end());
        set<int>ans2;
        for(int i=0;i<nums1.size();i++){
           if(s2.find(nums1[i])==s2.end()){
             ans2.insert(nums1[i]);
           }
        }
        vector<vector<int>>finalans;
        vector<int>ans1v(ans1.begin(),ans1.end());
        vector<int>ans2v(ans2.begin(),ans2.end());
finalans.push_back(ans2v);
finalans.push_back(ans1v);
return finalans;
    }
};