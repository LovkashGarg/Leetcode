class Solution {
public:
    int triangleNumber(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long finalans = 0;
        for (int i = 0; i < n - 2; i++) {
            int k=i+2;
            for (int j = i + 1; j < n - 1 && arr[i] != 0 ;j++) {

            
                while (k < n  && arr[i]+ arr[j] >arr[k]) {
                   k++;
                }

                finalans+= k-j-1;
            }
        }

        return finalans;
    }
};