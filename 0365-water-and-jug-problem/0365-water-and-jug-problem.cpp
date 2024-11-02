#include <unordered_map>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
    }
};
class Solution {
   
public:
   bool solve(int currx,int curry, int target,int x,int y,unordered_map<pair<int, int>, int, pair_hash> &m
){

    if(currx + curry ==target){
        return true;
    }
    if(m[{currx,curry}]==1){
       return false;
    }
   // ek baar ek kam kardiya to dobara nhi karna
    m[{currx,curry}]=1;

     // the  3 operations are
     // first is to completely fill the jug 
     bool ope1=solve(x,curry,target,x,y,m) || solve(currx,y,target,x,y,m);

     bool ope2=solve(0,curry,target,x,y,m) || solve(currx,0,target,x,y,m);

     int maxcanbeRemovedfromy=min(x-currx,curry);
      int maxcanbeRemovedfromx=min(currx,y-curry);
      // I tried to empty y to x 
     bool ope3= solve(currx+maxcanbeRemovedfromy,curry-maxcanbeRemovedfromy,target,x,y,m);
    // bool ope3 = solve(currx + min(curry, x - currx), curry - min(curry, x - currx), target, x, y, m);
      // I tried to empty x to y
     bool ope4= solve(currx-maxcanbeRemovedfromx,curry+maxcanbeRemovedfromx,target,x,y,m);

       // Transfer water between jugs
        // bool ope4 = solve(currx - min(currx, y - curry), curry + min(currx, y - curry), target, x, y, m);


     return ope1 || ope2 || ope3  || ope4;

   }
    bool canMeasureWater(int x, int y, int target) {
        if(x+y <target){
            return false;
        }
        if(x+y==target){
            return true;
        }
       unordered_map<pair<int, int>, int, pair_hash> m;
        return solve(0,0,target,x,y,m);
    }
};