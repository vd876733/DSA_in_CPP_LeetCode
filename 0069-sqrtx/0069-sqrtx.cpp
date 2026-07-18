class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int l = 0 ;
        int r = x ;
        int a = 0;
        while( l <= r){
            long long m = l+( r - l ) / 2;
            if( m* m == x){
                return m;
            }else if ( m* m < x){
                a = m;
                l = m+1;
            }else{
                r = m- 1;
            }
        }
        return a;
    }
};