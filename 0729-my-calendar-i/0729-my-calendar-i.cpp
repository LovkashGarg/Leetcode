class MyCalendar {
public:
   vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    

    bool book(int startTime, int endTime) {

        for (auto& interval : v) {
            // agar main interval ka startTime agar equal ata hai ya bda hota hai loop vale ke to koi dikat nhi or agar endtime vala chota ata hai then also no problem 
            if (!(endTime <= interval.first || startTime >= interval.second)) {
                return false; // Overlap detected
            }
        }

        v.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */