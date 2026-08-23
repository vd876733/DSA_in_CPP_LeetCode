class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' ||
               c == 'i' || c == 'o' ||
               c == 'u';
    }
    long long countAtLeast(string& word, int k) {
        vector<int> freq(26, 0);
        long long ans = 0;
        int left = 0;
        int consonants = 0;
        int uniqueVowels = 0;
        for (int right = 0; right < word.size(); right++) {
            char c = word[right];
            if (isVowel(c)) {
                if (freq[c - 'a'] == 0) {
                    uniqueVowels++;
                }
                freq[c - 'a']++;
            }
            else {
                consonants++;
            }
            // Window is valid
            while (uniqueVowels == 5 && consonants >= k) {
                char ch = word[left];
                if (isVowel(ch)) {
                    freq[ch - 'a']--;
                    if (freq[ch - 'a'] == 0) {
                        uniqueVowels--;
                    }
                }
                else {
                    consonants--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return countAtLeast(word, k)
             - countAtLeast(word, k + 1);
    }
};