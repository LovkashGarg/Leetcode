class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            cout<< intervals[i][0]<<" "<< intervals[i][1]<<endl;
            // means we have to merge
            if (i != intervals.size() - 1) {

                if (r >= intervals[i + 1][0]) {
                    r = max(intervals[i + 1][1],r);
                    //   i=i+1;
                } else {
                    // means normal
                    ans.push_back({l, r});

                    l = intervals[i + 1][0];
                    r = intervals[i + 1][1];
                }
            } else {
                ans.push_back({l, r});
            }
        }
        return ans;
    }
};