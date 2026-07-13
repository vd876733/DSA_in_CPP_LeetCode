class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3) {
            return -1;
        }
        vector<int> temp;
        temp.push_back(nums[0]);
        temp.push_back(nums[1]);
        temp.push_back(nums[2]);
        sort(temp.begin(), temp.end());
        return temp[1];
    }
};