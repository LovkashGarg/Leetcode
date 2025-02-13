class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        // we place all the values of max freq elements at a n gap 
        // now for last round we place all the elements with max frequency  
        // ex for a, a, a, b, b, b  n=2 
        // we place them{ a , _ , _ , a , _ , _ } done 
        // now for last round we place all the elements with max freq=3
        // ex for a , _ , _ ,a , _ , _ , a ,  b 
        // now rest are already placed at a gap of n


        int ans = (count-1)*(n+1);
        int s=tasks.size();
        for(auto e : mp){
if(e.second == count) ans++;
        } 
        return max(s, ans);
    }
};