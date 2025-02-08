class Solution {
public:
    int count=0;
    map<string ,string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string temp=to_string(count);
        m[temp]=longUrl;
        count++;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

          return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));