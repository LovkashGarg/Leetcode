class MyQueue {
public:
    stack<int> s;
    int top;
    MyQueue() {}

    void push(int x) { 
        if(s.size()==0){
top=x;
        }
        s.push(x);
     }

    int pop() {
        
        if (s.size() == 1) {
            int val = s.top();
            s.pop();
            top=INT_MAX; // now  no top 
            return val;
        }
        int val;
        // since stack top is the q back
        vector<int> temp;
        while (true) {
            top=s.top();
            temp.push_back(s.top());
            s.pop();

            if (s.size() == 1) {
                val = s.top();
                s.pop();
                break;
            }
        }

        for(int i=temp.size()-1;i>=0;i--){
            s.push(temp[i]);
        }
        return val;
    }

    int peek() {
       return top;
    }

    bool empty() {
        if (s.size() == 0) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */