class Solution {
public:
    string reverseVowels(string s) {
        int i = 0 , j = s.size()-1;
        string vowels = "aeiouAEIOU";

        auto isVowel = [&](char c){
            return vowels.find(c) != string::npos;
        };

        while( i < j){
            while( i < j && !isVowel(s[i])) i++;
            while( i < j && !isVowel(s[j])) j--;

            if( i < j){
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            
        }
        return s ;
    }
};