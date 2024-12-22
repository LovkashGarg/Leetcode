class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> visited(n, 0);

        /// time complexicity is O(n+ n)
        stack<pair<int,int>> s; // to store only post direction asteriod
        for (int i = 0; i < n; i++) {

            if (asteroids[i] > 0) {
                s.push({asteroids[i],i});
            } else {

                // if no positive element continue
                if (s.empty()) {
                    continue;
                } else {

                    // wo kath tee  raho

                    while (!s.empty()) {
                        if (s.top().first > abs(asteroids[i])) {
                            visited[i]=1;
                            break;
                        } else if (s.top().first < abs(asteroids[i])) {
                             visited[s.top().second]=1;
                             s.pop();
                        } else {
                            visited[s.top().second]=1;
                            s.pop();
                            visited[i] = 1;
                            break;
                        }
                    }
                }
            }


        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                ans.push_back(asteroids[i]);
            }
        }
return ans;
    
    }
};