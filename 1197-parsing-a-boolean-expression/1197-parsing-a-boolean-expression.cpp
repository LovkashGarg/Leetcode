class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>s;
        int n=exp.size();
        
        for(int i=0;i<n;i++){
          if(exp[i]=='(' || exp[i]=='t' || exp[i]=='f'){
            s.push(exp[i]);
          }
          else if(exp[i]=='&' || exp[i]=='|' || exp[i]=='!' ){
            s.push(exp[i]);
          }
          // means we have a closing bracket 

          else if(exp[i]==')'){
            vector<int>val;
            while(!s.empty() && s.top() !='('){
                if(s.top() == 't'){
                    val.push_back(1);
                }
                else{
                    val.push_back(0);
                }
                s.pop();
            }

            // check for operator 
            s.pop(); // removing opening brackets 
            
            char oper=s.top();
            s.pop();
            if(oper== '&'){
                int ans=1;
                for(auto i:val){
                 ans=ans & i;
                }

                if(ans==0){
                    s.push('f');
                }
                else{
                    s.push('t');
                }
            }
            else if(oper== '|'){
                int ans=0;
                for(auto i:val){
                 ans=ans | i;
                }

                if(ans==0){
                    s.push('f');
                }
                else{
                    s.push('t');
                }
            }
            else if(oper=='!'){
                 int ans= val[0];
                 if(ans==1){
                    s.push('f');
                }
                else{
                    s.push('t');
                }
            }
            
          }
          
        }
        if(s.top()=='t'){
            return true;
        }
        return false;
    }
};