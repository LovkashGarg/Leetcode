class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int maxal=0;
        int n=gain.size();
        int pre=0;
        for(int i=0;i<n;i++){
          pre+=gain[i];
          maxal=max(maxal,pre);
        }
        return maxal;
    }
};