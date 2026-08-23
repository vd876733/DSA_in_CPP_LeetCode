class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int left = 0;
        int count = 1;
        int ans = 0;
        for (int right = 1; right < word.size(); right++) {
            // Order is broken
            if (word[right] < word[right - 1]) {
                left = right;
                count = 1;
            }
            // New vowel
            else if (word[right] > word[right - 1]) {
                count++;
            }
            // All 5 vowels are present
            if (count == 5) {
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};