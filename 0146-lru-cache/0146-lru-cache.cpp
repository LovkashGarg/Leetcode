class LRUCache {
public:
     // here first is priority and second is key 
    set<pair<int,int>> s;
    // here first is key then is its priority and also value 
    unordered_map<int,pair<int,int> >m;
    int priority=-1;
    int len=0;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        this->len=cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(m.find(key)== m.end()){
            return -1;
        }
        else{
            // agar hai to uske priority change kardo 
            auto temp= m[key];
            int val=temp.second;
            int getprior=m[key].first;
            s.erase({getprior,key}); //  I erase it 
            priority++;
            s.insert({priority,key});
            m[key]={priority,val};
            
            return val;
        }
        
        
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        
        // your code here
        // important if size == capacity and we go to update we donot need to erase the least recently used 
        if(m.find(key)!=m.end()){
           int oldprior= m[key].first;
           s.erase({oldprior,key});
        }
        else if((this->s.size())>=len){
            // I need to remove with lowest priority 
            auto remo=*s.begin();
            int firstkey=remo.second;
            s.erase(s.begin());
            m.erase(firstkey);
        }
        
        // 
         priority++;
        s.insert({priority,key});
        m[key]={priority,value};
       
        
    }
    
}
;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */