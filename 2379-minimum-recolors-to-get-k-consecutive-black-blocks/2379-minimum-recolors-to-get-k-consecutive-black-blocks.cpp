class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        // Count whites in first window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
        }
        int ans = white;
        // Slide the window
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') {
                white--;
            }
            if (blocks[i] == 'W') {
                white++;
            }
            ans = min(ans, white);
        }
        return ans;
    }
};