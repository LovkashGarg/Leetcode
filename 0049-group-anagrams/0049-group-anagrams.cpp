class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // Here I can make a 2d array which contains freq of all the 26 elements 

        // time complexicity is 0(n*log(n)) 
        map<string,vector<string>>m;
         for(auto i:strs){
            string word=i;
            sort(word.begin(),word.end());
            m[word].push_back(i);
         }
         vector<vector<string>>ans;
         for(auto i:m){
vector<string>temp;
            for(auto j: i.second){
                temp.push_back(j);
             
            }
            ans.push_back(temp);
          
         }
        return ans;
    }
};