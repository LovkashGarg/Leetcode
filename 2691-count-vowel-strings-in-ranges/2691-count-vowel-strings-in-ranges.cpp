class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> prefixSum(words.size());
        int sum = 0;
        // for each word count the number of words with ending with vowel  
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            if (vowels.count(currentWord[0]) &&
                vowels.count(currentWord[currentWord.size() - 1])) {
                sum++;
            }
            prefixSum[i] = sum;
        }

        // for each query i have to check if it is startinf from 0 or not if yes then complete ans 
        // else answer is 

        for (int i = 0; i < queries.size(); i++) {
            vector<int> currentQuery = queries[i];
            ans[i] =
                prefixSum[currentQuery[1]] -
                (currentQuery[0] == 0 ? 0 : prefixSum[currentQuery[0] - 1]);
        }

        return ans;
    }
};