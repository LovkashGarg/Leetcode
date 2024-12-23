class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxarea = 0;
        vector<int> pse(n);

        // time complexicity is O()
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                // this means here i is the next smaller element for s.top()
                // since it took out  the element nse[s.top()]=i we know formula
                // for width is nse -pse -1
                maxarea =
                    max(maxarea, heights[s.top()] * (i - pse[s.top()] - 1));
                s.pop();
            }

            if (s.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = s.top();
            }
            s.push(i);
        }

        // now the element left in the array are the one which do not have a
        // previous smaller element and no next smaller element

        while (!s.empty()) {

            auto ele = s.top();
            s.pop();
            int nse = n; // next smaller element not present since no element
                         // left after that
            int pse;
            if (s.empty()) {
                pse = -1;
            } else {
                pse = s.top();
            }
            maxarea = max(maxarea, heights[ele] * (nse - pse - 1));
        }
        return maxarea;
    }
};