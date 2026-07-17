class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0;
        int a = 0;
        for( int i = 0 ; i < s.size() ; i++){
            while(set.count(s[i])){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[i]);
            a = max( a , i - l + 1);
        }
        return a;
    }
};