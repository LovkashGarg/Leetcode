class TimeMap {
public:
        map<string,multiset<int> >m;
        map<int,string>time_to_val;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
            m[key].insert(timestamp);
            time_to_val[timestamp]=value;
    }
 string get(string key, int timestamp) {
        auto &s = m[key]; // Reference to avoid copying

        auto it = s.lower_bound(timestamp); // First element **≥** timestamp
    
        // If `it` points to the first element and is not exactly `timestamp`, no smaller element exists
        if (it == s.begin() && (*it) != timestamp) 
            return "";

        // If `it->first == timestamp`, return it directly
        if (it != s.end() && (*it) == timestamp) 
            return time_to_val[*it];

        // Otherwise, move `it` back to get the **largest key strictly smaller** than timestamp
        --it; 
        return time_to_val[*it];
    }


};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */