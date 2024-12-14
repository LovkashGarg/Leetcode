class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Here loggic is that we have two basisks now we have to calculate mak
        // I can form with till I have tow types of fruits in a subarray

        // Question framed Now
        // We have to find longest array with two characters

        int l = 0;
        int r = 0;
        int n = fruits.size();
        int basket1 = -1;
        int basket2 = -1;
        int lastindex1 = -1;
        int lastindex2 = -1;
        int maxlen = 0;
        while (r < n) {
            if (basket1 == fruits[r]) {
                lastindex1 = r;
                r++;
            } else if (basket2 == fruits[r]) {
                lastindex2 = r;
                r++;
            } 
            else if (basket1 == -1) {
                basket1 = fruits[r];
                lastindex1 = r;
                r++;
            } else if (basket2 == -1) {
                basket2 = fruits[r];
                lastindex2 = r;
                r++;
            } else {
                // means it is not the type of fruit we wanted

                // find min of both

                maxlen = max(maxlen, r - l);

                int mini = min(lastindex1, lastindex2);
                
                // jiska min uthaya hai
                // uske next wala index apna l hoga

                l = mini + 1;
                if (mini == lastindex1) {
                    // matlab iswali basket ka fruit type badalna hai
                    basket1 = fruits[r]; // current fruit type
                    lastindex1 = r;
                } else {
                    // matlab iswali basket ka fruit type badalna hai
                    basket2 = fruits[r]; // current fruit type
                    lastindex2 = r;
                }
            }
        }
        // kyunki el element bahar bhi aagye hai
        maxlen = max(maxlen, r - l);
        return maxlen;
    }
};