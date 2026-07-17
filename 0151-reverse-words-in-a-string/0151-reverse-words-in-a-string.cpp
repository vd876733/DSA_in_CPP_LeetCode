class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin() , s.end());
        string ans = "";

        for( int i = 0 ; i < s.size() ; i++){
             if (s[i] == ' ') {
                continue;
            }

            string word = "";
            while( i < s.size() &&  s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin() , word.end());
             if (!ans.empty()) {
                ans += " ";
            }

            ans += word;
            
        }
        return ans;
    }
};