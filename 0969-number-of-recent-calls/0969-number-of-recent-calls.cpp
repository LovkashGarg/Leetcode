class RecentCounter {
public:

    set<int>s;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        s.insert(t);
        int count=0;
        for(auto it=s.rbegin();it!=s.rend();it++){
            // now here 
            if(*it+ 3000 <t ){
                break;
            }
            count++;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */