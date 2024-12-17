class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
       vector<int> v(26,0);
       priority_queue<pair<char,int>>pq;
       priority_queue<pair<char,int>>pq2;
       int n=s.size();
       for(int i=0;i<s.size();i++){
        v[s[i]-'a']++;
       }

       for(int i=0;i<26;i++){
        if(v[i]!=0){
        pq.push({'a'+i,v[i]});
        }
       }

 string ans;
       while(!pq.empty()){
        // take out the character 
        auto temp=pq.top();
        char d=temp.first;
        int f=temp.second;
        cout<<d<<f<<endl;
        pq.pop();
       
        // remove only the repeatcount 
        int charremoved=min(repeatLimit,f);
       string l=string(charremoved,d);
       cout<<l<<endl;
        

        ans+=l;
         
        if(charremoved<f){
            char c;
            int n2=0;
            if(!pq.empty()){
                 c=pq.top().first;
                 n2=pq.top().second;
                 pq.pop();
            }
            else{
                return ans; // if there is no character left 
            }
            ans+=c; // adding next priority character to ans only once

            pq.push({d,f-charremoved});
            // agar kuch usme bhi bacha hai to 
            if(n2-1 >0){
            pq.push({c,n2-1});
            }
        }
       }

       return ans;
       
    }
};