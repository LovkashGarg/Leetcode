class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        int n = startGene.size();
        unordered_set<string> s(bank.begin(),bank.end());
       
        s.erase(startGene);
        while (!q.empty()) {
            string value = q.front().first;
            int dis = q.front().second;
            if (value == endGene) {
                return dis;
            }
            q.pop();

            for (int i = 0; i < n; i++) {
                char d=value[i];
                for(char j='A' ;j<='Z';j++){
                  value[i]=j;
                  if(s.find(value)!=s.end()){
                    s.erase(value);
                    q.push({value,dis+1});
                  }

                }
                value[i]=d;
            }
        }
            return -1;
        }
    };