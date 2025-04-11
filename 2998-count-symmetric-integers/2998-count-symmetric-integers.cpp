class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int count=0;
        for(int i=low;i<=high;i++){
            if(i>=1&& i<=9){
              continue;
            }
            else if(i>=10 && i<=99){
                 
                 int second= i%10; // last number 
                 int first = i/10;
                 if(first == second){
                    count++;
                 }

            }
            if(i>=100 && i<=999){
                continue;
            }
            else if(i>=1000&& i<=9999){
                int num=i;
                  int last= i%10; // last number 
                  num=num/10;
                  int secondlast= num%10;
                  num=num/10;
                  int thirdlast= num%10;
                  num=num/10;
                  int first=num;
                  if(first + thirdlast == secondlast + last){
                    count++;
                  }
                
            }
            else{
               continue;
            }

        }
        return count;
    }
};