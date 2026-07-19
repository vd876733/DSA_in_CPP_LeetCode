class Solution {
public:

    bool check(vector<int>& weights , int days , int c){
        int cw = 0;
        int ud = 1;
        for( int i = 0 ; i < weights.size( ) ; i++){
            if(cw + weights[i] <= c){
                cw += weights[i];
            }
            else{
                ud++;
                cw = weights[i];
            }
        }
        if( ud <= days){
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int r = accumulate(weights.begin() , weights.end() , 0);
        while( l < r){
            int m = l + ( r - l) / 2;
            if(check(weights , days , m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};