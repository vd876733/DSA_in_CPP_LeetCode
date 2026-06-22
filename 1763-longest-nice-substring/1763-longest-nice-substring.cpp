class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) {
            return "";
        }
        unordered_set<char> st;
        for(int i = 0; i < s.size(); i++) {
            st.insert(s[i]);
        }
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(st.count(tolower(ch)) &&
               st.count(toupper(ch))) {
                continue;
            }
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));
            if(left.size() >= right.size()) {
                return left;
            }
            return right;
        }
        return s;
    }
};