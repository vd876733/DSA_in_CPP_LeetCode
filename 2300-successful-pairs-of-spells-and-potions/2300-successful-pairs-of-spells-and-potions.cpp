class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++) {
            int left = 0;
            int right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (1LL * spells[i] * potions[mid] >= success) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            ans.push_back(m - left);
        }
        return ans;
    }
};