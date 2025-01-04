class StockSpanner {
public:
  // Here I need to check for the previous greater element 
  // now but since I need to count the number of element also so I need a index also 
    stack<pair<int,int>>s;
    int index;
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        
        index++; // current index 
        int n=s.size();
        int ans=1;
        
        // time complexicity is O(n) max
        while(!s.empty() && s.top().first <=price){
            s.pop();   
        }

        if(!s.empty()){
            // current index is 4 and the pge is at index 7 means total ele are 1 ,2, 3 
          ans= index - s.top().second -1 +1 ;
          // +1 since we count the current element also 
        }
        else{
            // means no previous greater element 
            // eg for first element we do not have a greater element threfore 
            ans= index+1;
        }

        
        s.push({price,index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */