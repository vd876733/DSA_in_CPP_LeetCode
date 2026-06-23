class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }
        int maxFreq = 0;
        for(int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }
        int countMax = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == maxFreq) {
                countMax++;
            }
        }
        return max((int)tasks.size(),(maxFreq - 1) * (n + 1) + countMax);
    }
};