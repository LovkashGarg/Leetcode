class Solution {
public:
    int findNthDigit(int n) {
        // after each digit place increase
        // for 1 to 9 we have 9*1 digits
        // for 10 to 99 we have 90*2 digits
        // for 100 to 999 we have 900*3 digits

        // preproccessing
        vector<int> digitsforEachplace(1000, 0);
        long int d = 9;
        if (n <= 9) {
            return n;
        }
        int totalnumberpassed = 0;
        for (int i = 1;; i++) {
            long long int value = digitsforEachplace[i - 1] + d * i;
            digitsforEachplace[i] = value;
            // cout<<value<<endl;
            // means number is here
            if (value >= n) {
                // cout<<"total digits passed" <<totalnumberpassed<<endl;
                // these are the digits gone for this place
                long long int digitsgone = n - digitsforEachplace[i - 1];
                cout << "digits gone" << digitsgone << endl;
                long long int numbersplacing = ceil(float(digitsgone) / i);
                // for n=11 we have 11-9 =2 these are the number of digits gone
                // number gone =2/1 one number
                //    cout<<"number placing "<<numbersplacing<<endl;
                long long int actualnumber = totalnumberpassed + numbersplacing;
                cout << "actual number" << actualnumber << endl;
                int digitsplacingforthatnumber = (digitsgone % (i));
                
                if (i == 2) {
                    if (digitsplacingforthatnumber == 0) {
                        return actualnumber % 10;
                    } else {
                        return actualnumber / 10;
                    }
                }
                int count = 0;
                cout << i << endl;
                
                cout << "digits placing " << digitsplacingforthatnumber << endl;
                if(digitsplacingforthatnumber==0){
                    return actualnumber%10;
                }
                digitsplacingforthatnumber = i - digitsplacingforthatnumber + 1;
                // cout << "digits placing " << digitsplacingforthatnumber << endl;
              
                while (actualnumber != 0) {
                    long long int m = actualnumber % 10;
                    count++;
                    if (count == digitsplacingforthatnumber) {
                        return m;
                    }
                    actualnumber = actualnumber / 10;
                }
            }
            totalnumberpassed += d;
            d = d * 10;
        }

        return 1;
    }
};