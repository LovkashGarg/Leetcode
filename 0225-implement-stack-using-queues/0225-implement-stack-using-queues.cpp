class MyStack {
public:
    queue<int>q;

    MyStack() {
         
    }
    
    void push(int x) {
        q.push(x); // this would push it from back 
    }
    
    int pop() {
     // when I have to pop I need to pop the last element 
        if(q.size()==1){
            int val=q.front();
            q.pop();
            return val;
        }

        int val=q.back();
        queue<int>temp;

        while(true){
          temp.push(q.front());
          q.pop();
          if(q.size()==1){
            break;
          }
        }
        
        q=temp;
        return val;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */