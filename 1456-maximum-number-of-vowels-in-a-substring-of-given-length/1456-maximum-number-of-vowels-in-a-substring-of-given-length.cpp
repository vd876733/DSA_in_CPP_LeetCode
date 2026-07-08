class Solution {
public:

    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }
        int ans = count;
        for (int right = k; right < s.size(); right++) {
            if (isVowel(s[right])) {
                count++;
            }
            if (isVowel(s[right - k])) {
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};