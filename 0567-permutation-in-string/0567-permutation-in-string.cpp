class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        // Frequency of s1
        for (int i = 0; i < s1.size(); i++) {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        if (mp1 == mp2) {
            return true;
        }
        // Sliding Window
        for (int i = s1.size(); i < s2.size(); i++) {
            // Add new character
            mp2[s2[i]]++;
            // Remove left character
            mp2[s2[i - s1.size()]]--;
            // Remove key if frequency becomes 0
            if (mp2[s2[i - s1.size()]] == 0) {
                mp2.erase(s2[i - s1.size()]);
            }
            if (mp1 == mp2) {
                return true;
            }
        }
        return false;
    }
};