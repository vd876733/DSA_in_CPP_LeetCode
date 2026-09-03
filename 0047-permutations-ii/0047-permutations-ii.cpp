class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<bool>& used,vector<int>& temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            // Skip duplicate choices at the same level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used, temp);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        backtrack(nums, used, temp);
        return ans;
    }
};