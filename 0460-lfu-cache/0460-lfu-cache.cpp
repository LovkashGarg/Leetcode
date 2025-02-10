class LFUCache {
public:
int d;
int priority=-1;
// first is my frequency and then if tie then handle the recently used  then we have key 
set<pair<int,pair<int,int>>>s;
// first is key then freq then  priority then value 
unordered_map<int,pair<int,pair<int,int>> > m;

    LFUCache(int capacity) {
        this->d=capacity;
    }
    
    int get(int key) {

        if(m.find(key)==m.end()){
            return -1;
        }
        else{
            // I have to return 
            int freq=m[key].first;
            int prior=m[key].second.first;
            int old_val=m[key].second.second;
              s.erase({freq,{prior,key}}); // here I can delete it 
            freq++;
            priority++;
            m[key]={freq,{priority,old_val}};
            s.insert({freq,{priority,key}});
            return old_val;
        }
    }
    
    void put(int key, int value) {
          
          // I have already present 
          if(m.find(key)!=m.end()){
           int freq=m[key].first;
           int prior=m[key].second.first;
           s.erase({freq,{prior,key}});
        //    int oldvalue=m[key].second.second; // newvalue is there

           // I have to increase the freq 
           freq++;
           priority++;
           m[key]={freq,{priority,value}};
           s.insert({freq,{priority,key}});

          }
          else if( m.size() >=d){
            // I have to erase the first element 
            auto temp=*s.begin();
            int firstkey= temp.second.second;
            int firstfreq=m[firstkey].first;
            int firstprior=m[firstkey].second.first;
            m.erase(firstkey);
            s.erase({firstfreq,{firstprior,firstkey}});
            priority++;
            s.insert({1,{priority,key}});
            m[key]={1,{priority,value}};
          }
          else{
            // newest element 
            priority++;
            m[key]={1,{priority,value}};
            s.insert({1,{priority,key}});
          }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */