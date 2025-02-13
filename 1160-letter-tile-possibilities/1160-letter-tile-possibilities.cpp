class Solution {
public:
    int numTilePossibilities(string tiles) {
	   
      vector<int>counts(26,0);
        for (const auto &c :  tiles) {  // count the number of occurences of each character in the alphabet
            counts[c - 'A']++;
        }
        int result = 0;
        rec(counts, result);
        return result;
    }
    
	
    void rec(vector<int>&counts, int &result) {
        for(int i = 0; i < 26; ++i) {
            if (counts[i]){
                counts[i]--;
                result++;
                rec(counts, result);
                counts[i]++;
            }
        }
    }
};