class Solution {
public:
    bool canChange(string start, string target) {

     priority_queue<pair<int,char>>pq1;
     priority_queue<pair<int,char>>pq2;
     for(int i=0;i<start.size();i++){
     if(start[i]=='L' || start[i]=='R'){
       pq1.push({i,start[i]});
     }
     }

     for(int i=0;i<target.size();i++){
    if(target[i]=='L' || target[i]=='R'){
        pq2.push({i,target[i]});
    }
     }

     // now my task is to find the Index which can satisfy his need 
   if(pq1.size() !=pq2.size()){
    return false;
   }
   while(!pq1.empty() && !pq2.empty()){
    auto index1=pq1.top().first;
    auto d1=pq1.top().second;
    pq1.pop();

    auto index2=pq2.top().first;
    auto d2=pq2.top().second;
    pq2.pop();

    // since we cant jump over anyone relative order remain same 
    if(d1 !=d2){
        return false;
    }

    // matlab ki shift ho sakti hai 
    if(index1==index2){
        continue;
    }
   else if(index1 <index2 && d1 =='R'){
   continue;
   }
   else if( index1 >index2 && d1=='L'){
    continue;
   }else{
    return false;
   }
    // cout<<index1 << " "<<index2 << " "<< d1 << " "<<d2<<endl;
   }
  

     return true;


    }
};