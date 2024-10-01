class Solution {
public:
    int characterReplacement(string s, int k) {
       int l=0;
       int r=0;
       int maxlen=0;
       int maxfreq=0;
       int n=s.length();
       vector<int>hash(26,0);
       
       while(r<n){
           hash[s[r]-'A']++;
        //    cout<<s[r]<<" "<<hash[s[r]-'A']<<endl;
           maxfreq=max(maxfreq, hash[s[r]-'A']);
        //  cout<<"maxfreq "<<maxfreq<<endl;
           int noofchanges=(r-l+1) - ( maxfreq);
            while(((r-l+1)- maxfreq) >k){
             
                // cout<<s[l]<<" "<<hash[s[r]-'A']<<endl;
               
                 hash[s[l]-'A']--;
                 maxfreq=0;
                 // we check frequncy since we may remove the element with hightest freq
                 for(int i=0;i< 26;i++){
                  maxfreq=max(maxfreq, hash[i]);
                 }
                 l++;
            }
            //  cout<<"done"<<endl;
            // update the maxlen if change less than = k
           if((r-l+1)- maxfreq<=k){
            maxlen=max(maxlen, (r-l+1));
           }
        //    cout<<maxlen<<endl;
           r++;
       }
       return maxlen;
    }
};