class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> s;
        for (int i = 0; i < wordList.size(); i++) {
            s.insert(wordList[i]);
        }
        queue<pair<string, int>> q;
        q.push({beginWord,1});
        int n = beginWord.size();
        while (!q.empty()) {
            string value = q.front().first;
            int dis = q.front().second;
            if(value==endWord){
                return dis;
            }
            q.pop();
            for (int i = 0; i < n; i++) {
                // checking for each letter
                for (int j = 0; j < 26; j++) {
                    char d = j + 'a';
                    swap(value[i], d);
                    auto pos = s.find(value);
                    if (pos != s.end()) {
                      q.push({*pos, dis + 1});
                        // cout << *pos <<dis+1<< endl;
                        s.erase(*pos);
                    }
                    swap(value[i], d);
                }
            }
        }

        return 0;

        // because from steck insertion and deletion is easy
    }
};