class Solution {
public:
    int dp( int num){
        int p = 1;
        while( num > 0){
            p *= (num % 10);
            num = num / 10;
        } 
        return p;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int p = dp(n);
            if( p % t == 0){
                return n;
            }
            n++;
        }
    }
};