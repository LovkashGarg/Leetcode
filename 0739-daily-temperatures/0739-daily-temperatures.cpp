class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        vector<int>ans;
        map<int,int>m;
        int n=temperatures.size();
        for(int i=0;i<n;i++){
      m[temperatures[i]]=i;
        }
        // monotonic stack means we are storing the element in a specific order 
        s.push(temperatures[n-1]);
        ans.push_back(0);
        for(int i=n-2;i>=0;i--){
            // cout<<" temperatures"<<temperatures[i]<<endl;
            if(temperatures[i]<s.top()){
                cout<<s.top()<<endl;
                ans.push_back(m[s.top()]-i);
                 s.push(temperatures[i]);
            }
            // if this element is greater than stack top 
            else {
        
                 
                while(!s.empty() && s.top() <= temperatures[i] ){
                    if(s.top()== temperatures[i]){
                        m[s.top()]=i;
                    }
                  s.pop();
                }
                if(s.empty()){
                ans.push_back(0);
                }
                else{
                    ans.push_back(m[s.top()]-i);
                }
                s.push(temperatures[i]);
            }
            // cout<<"print"<<endl;
            //     stack<int> d=s; 
            //     while(!d.empty()){
            //         cout<<d.top()<<endl;
            //         d.pop();
            //  } 
             m[temperatures[i]]=i;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};