class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < queries.size(); i++) {
            v.push_back({queries[i], i});
        }
        sort(v.begin(), v.end());
        // for(auto i:items){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        vector<int> ans(queries.size());

        int i = 0;
        int val = 0;
        // time complexicity is 0(queries.size() + items.size() +o( queries.size()*log(queries.size())))
        for (int j = 0; j < queries.size(); j++) {
            // checking for each query
            auto price = v[j].first;
            // cout<<price << " "<<val<<endl;
            while (i < items.size() && price >= items[i][0]) {
                val = max(val, items[i][1]);
                i++;
            }
            ans[v[j].second] = val;
        }
        return ans;
        /// I can say apply binary search for each queries for price equal
    }
};