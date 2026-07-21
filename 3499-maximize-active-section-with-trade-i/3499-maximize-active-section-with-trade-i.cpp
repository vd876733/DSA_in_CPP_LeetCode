class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int totalOnes = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                totalOnes++;
        }
        vector<pair<char, int>> blocks;
        int i = 0;
        while (i < n) {
            char ch = s[i];
            int cnt = 0;
            while (i < n && s[i] == ch) {
                cnt++;
                i++;
            }
            blocks.push_back({ch, cnt});
        }
        int gain = 0;
        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' && blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {
                gain = max(gain,blocks[i - 1].second + blocks[i + 1].second);
            }
        }
        return totalOnes + gain;
    }
};