

class Solution {
public:
  map<int,vector<TreeNode*>> dp={  {0, {}},                     // Empty vector for n = 0
        {1, {new TreeNode(0)}}  };
   
    vector<TreeNode*> allPossibleFBT(int n) {
       
        if(n%2==0){
            return {};
        }

        if(dp.count(n)){
          return dp[n];
        }
        
        vector<TreeNode*> res;
        for (int l = 0; l < n; l++) {
            int r = n - 1 - l; // one subtracted for root node
            vector<TreeNode*> leftsub = allPossibleFBT(l);
            vector<TreeNode*> rightsub = allPossibleFBT(r);

            for (TreeNode* i : leftsub) {
                for (TreeNode* j : rightsub) {
                    res.push_back(new TreeNode(0, i, j));
                }
            }
        }


        return res;
    }
};
