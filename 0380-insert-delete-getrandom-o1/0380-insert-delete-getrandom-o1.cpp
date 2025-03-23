class RandomizedSet {
public:
unordered_set<int>s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return false;
        }
        else{
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
          if(s.find(val)!=s.end()){
           auto it= s.find(val);
            s.erase(it);
            return true;
        }
        else{
            return false;
        }

    }
    
    int getRandom() {
        int n= s.size();
        int d=rand() %n;
        auto it = s.begin();
        advance(it, d); // Manually advance the iterator
        return *it;

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */