class Solution {
public:
    bool rotateString(string s, string goal) {
        // matlab string ko do bar add karlo do reapeat ho hijayegi
       return s.size() == goal.size() && (s+ s).find(goal) != string::npos;
    }
};