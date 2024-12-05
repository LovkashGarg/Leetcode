class Solution {
public:
    bool canChange(string start, string target) {
        int a = start.size() - 1;
        int b = target.size() - 1;
        while (a >= 0 && b >= 0) {

            while (a >= 0 && start[a] == '_') {
                a--;
            }
            while (b >= 0 && target[b] == '_') {
                b--;
            }

            if (a >= 0 && b >= 0) {
                if (start[a] != target[b]) {
                    return false;
                }
                else if(a==b ){
                    a--;
                    b--;
                }
                else if (a < b && start[a] == 'R') {
                    a--;
                    b--;
                } else if (a > b && start[a] == 'L') {
                    a--;
                    b--;
                } else {
                    return false;
                }
            }
            // koi extra element hai 
            else if( a< 0 && b>=0){
                return false;
            }
            else  if(a>=0 && b<0){
                return false;
            }
        }

        while(a>=0 && start[a]=='_'){
            a--;
        }
          while(b>=0 && target[b]=='_'){
            b--;
        }
        if(a!=b){
            return false;
        }
      
        return true;
    }
};