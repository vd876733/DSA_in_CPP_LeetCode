class Solution {
public:
    void reverseString(vector<char>& s) {
        rev(s,0,s.size() - 1);
    }
    void rev(vector<char>& s , int l , int r ){
        if( l >= r){
            return;
        }
        swap(s[l] , s[r]);

        rev(s,l+1 , r-1);
    }
};