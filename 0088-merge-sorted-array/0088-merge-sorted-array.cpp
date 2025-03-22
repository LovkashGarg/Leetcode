class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

         if(n==0){
            return;
        }

        if(m==0){
            nums1=nums2;
            return;

        }
        int i = 0;
        int j = 0;
        while (i < m ) {
            if (nums1[i] <= nums2[j]) {
                i++;
            } else {
                // I need to place it at correct position

                swap(nums1[i], nums2[j]);
                int l = j+1;
                
                while (l< n && nums2[l-1] > nums2[l]) {
                    swap(nums2[l-1], nums2[l]);
                    l++;
                }
            }
        }

        

        for(int i=m;i<m+n;i++){
            nums1[i]= nums2[i-m];
        }

     
    }
};