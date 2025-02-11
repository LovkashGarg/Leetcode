class Solution {
public:
    void solve(int divident, unordered_map<int, int>& m, int index,vector<int>&ans) {

        // Now I can say
        for (int j = 1; j * j <= divident; j++) {
            // means perfect square
            if ((divident / double(j)) == j && m.find(j)!=m.end()) {
                ans[index]=min(m[j],ans[index]);
            } else if (divident % j == 0) {
               
                if(m.find(j)!=m.end()){
                     ans[index]=min(m[j],ans[index]);
                }
                if(m.find(divident/j)!=m.end()){
ans[index]=min(m[divident/j],ans[index]);
                }
   
            }

        }
    }
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = elements.size();
        int s = groups.size();
        unordered_map<int, int> m;

        // store the index of each divisor and it should be at min value 
        for (int i = n-1; i >=0; i--) {
            m[elements[i]] = i; 
        }

        // find all the factors of the each elemtn in groups
        vector<int>ans(s,INT_MAX);
        for (int i = 0; i < s; i++) {
            solve(groups[i], m,i, ans);
        }
        for(int i=0;i<s;i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;

        
    }
};