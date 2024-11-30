class Solution {
public:
    string reorganizeString(string s) {
        int maxi=0;
      unordered_map<char,int> m;
      int n=s.size();
      for(int i=0;i< n;i++){
        m[s[i]]++;
        maxi=max(maxi,m[s[i]]);
      }
      
      // not possible 
      if(maxi >ceil(n/2.0)){
        return "";
      }
      priority_queue<pair<int,char>>pq;
       vector<int>v(26,0);
     for(auto i : m ){
pq.push({i.second, i.first});
v[i.first -'a']= i.second;
     }
        // placing at even indexes 
      int i=0;
      for(int i=0;i<n;i+=2){
        auto d =pq.top().second;
        auto freq=pq.top().first;
        v[d-'a']--;
        if(v[d-'a']==0){
         pq.pop();
        }
        s[i]=d;

      }
     
      for(int i=1;i<n;i+=2){
        auto d =pq.top().second;
        auto freq=pq.top().first;
        v[d-'a']--;
        if(v[d-'a']==0){
         pq.pop();
        }
        s[i]=d;
      }

return s;

    }
};