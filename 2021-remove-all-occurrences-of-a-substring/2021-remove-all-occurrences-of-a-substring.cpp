class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
 
       // time complexict is O (n/m)
        while(s.find(part)!= string::npos){
            s.erase(s.find(part),m); // delete m characters 
        }

        return s;

    }
};