class Solution {
public:
    static bool bysize(const string & a, const string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        
        // we sorted in increasing size since when we try to see if the string is present then the value of dp is already calculated for that 

        sort(words.begin(), words.end(),bysize);
        unordered_map<string,int>m;

        int n=words.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            m[words[i]]=i;
            hash[i]=i;
        }

        int last=0;
        int maxlen=1;
        for(int i=0;i<n;i++){
             for(int j=0;j<words[i].size();j++){
                string news= words[i].substr(0,j) + words[i].substr(j+1);;
                
                if(m.count(news) && dp[m[news]] +1 > dp[i]){
                    dp[i]=max(dp[i] , dp[m[news]]+ 1 );
                    hash[i]=m[news];
                }

             }

             if(maxlen < dp[i]){
                maxlen=max(maxlen, dp[i]);
                last=i;
             }
             
        }
     
        return maxlen;

    }
};