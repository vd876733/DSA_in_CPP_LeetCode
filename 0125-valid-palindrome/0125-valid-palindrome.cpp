class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for( int i = 0 ; i < s.size() ; i++){
            if(isalnum(s[i])){
                a += tolower(s[i]);
            }
        }
            int l = 0;
            int r = a.length() - 1;
            while(l < r){
                if(a[l] != a[r]){
                    return false;
                }
                l++;
                r--;
            }
            return true;

        }
    
};