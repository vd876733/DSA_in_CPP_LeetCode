class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int pairs = 0;
        int left = 0;
        for (auto it : mp) {
            pairs += it.second / 2;
            left += it.second % 2;
        }
        return {pairs, left};
    }
};