class Solution {
public:
    vector<int> partitionLabels(string s) {

       vector<int>first(26,-1); 
       vector<int>last(26,-1); 

       int n= s.size();
       for(int i=0;i<n;i++){
         if(first[s[i]-'a']==-1){
          first[s[i]-'a']=i;
         }

         last[s[i]-'a']=i;

       }




       // now I have to merge this intervals 
       vector<pair<int,int>>  intervals;
       for(int i=0;i<26;i++ ){
         if(first[i] != -1 && last[i]!=-1){
            intervals.push_back({first[i],last[i]});
         }
       }

       
       sort(intervals.begin(),intervals.end());

       vector<pair<int,int>> merged;

       int start= intervals[0].first;
       int end= intervals[0].second;

       for(int i=1;i<intervals.size();i++){
         if(end > intervals[i].first ){
            end=max(end,intervals[i].second);
         }
         else{
            merged.push_back({start,end});
            start= intervals[i].first;
            end=intervals[i].second;
         }

       }

       merged.push_back({start,end});
       
       vector<int>ans;
       for(auto i:merged){
        ans.push_back( i.second-i.first +1);
       }

       return ans;
    }
};