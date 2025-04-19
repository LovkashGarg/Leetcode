class MyCalendarThree {
public:
    map<int,int>timeline;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
     timeline[startTime]++;
     timeline[endTime]--;
     int k=0;
     int ongoing=0;
     // provide us with the max ongoing processing at a moment 
     for(auto &i:timeline){
       k= max(k , ongoing+=i.second);
     }    
         
         return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */