class Solution {
public:
    set<string> news;

    void permut(int index, int n, string &m) {
        if (index >= n) {
            news.insert(m);
            return;
        }

        for (int i = index; i < n; i++) {
            swap(m[i], m[index]);
            permut(index + 1, n, m);
            swap(m[i], m[index]); 
        }
    }

    void solve(int index, int n, string &tiles, string &output, set<string> &s) {
        if (index >= n) {
            if (!output.empty()) 
                s.insert(output);
            return;
        }

        output.push_back(tiles[index]);
        solve(index + 1, n, tiles, output, s);
        output.pop_back();
        solve(index + 1, n, tiles, output, s);
    }

    int numTilePossibilities(string tiles) {
        set<string> s; // To store unique subsequences
        string output;
        int n = tiles.size();
        sort(tiles.begin(),tiles.end());
        solve(0, n, tiles, output, s);

        for (auto it : s) {
            string temp = it;
            permut(0, temp.size(), temp); 
        }

        return news.size(); 
    }
};
