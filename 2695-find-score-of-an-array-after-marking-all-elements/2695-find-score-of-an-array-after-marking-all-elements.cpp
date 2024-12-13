class Solution {
public:
    long long findScore(vector<int>& nums) {

        multiset<pair<int, int>> s;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        for (int i = 0; i < n; i++) {
            s.insert({nums[i], i});
        }
        int marked = 0;
        long long score = 0;
        vector<int> v(n, -1);
        while (marked < n) {
            auto temp = *s.begin();
            int value=temp.first;
            auto index =temp.second;
            v[index] = 1;
            auto it = s.find({nums[index],index});
            s.erase(it);
            marked++;
            score += value;

            if (index == 0) {
                // then mark only next element
                if (n >=2 && v[index+1] == -1) {
                    marked++;
                    v[index+1] = 1;
                    auto it = s.find({nums[index+1],index+1});
                    s.erase(it);
                } else {
                    continue;
                }
            }
            else if(index==n-1){
                if (n>=2  && v[index-1] == -1) {
                    marked++;
                    v[index-1] = 1;
                    auto it = s.find({nums[index-1],index-1});
                    s.erase(it);

                } else {
                    continue;
                }
            }
            else{

                 if (n>=2  && v[index-1] == -1) {
                    marked++;
                    v[index-1] = 1;
                    auto it = s.find({nums[index-1],index-1});
                     s.erase(it);
                 } 

                 if (n >=2 && v[index+1] == -1) {
                    marked++;
                    v[index+1] = 1;
                    auto it = s.find({nums[index+1],index+1});
                   s.erase(it);
                }

            }
        }
        return score;
    }
};