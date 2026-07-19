class Solution {
public:
    bool eat(vector<int>& piles , int h , int s){
        long long  hours = 0;
        for( int i = 0 ; i < piles.size() ; i++){
            hours += (piles[i] + s - 1) / s;
            if( hours > h){
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin() , piles.end());
        while( l < r){
            int m = l + ( r - l) /2;
            if(eat(piles , h , m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};