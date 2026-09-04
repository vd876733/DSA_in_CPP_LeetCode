class Solution {
public:
    vector<int> findIndices(vector<int>& nums,int indexDifference,int valueDifference) {
        int n = nums.size();
        int minIndex = 0;
        int maxIndex = 0;
        for (int j = indexDifference; j < n; j++) {
            int i = j - indexDifference;
            if (nums[i] < nums[minIndex])
                minIndex = i;
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
            if (nums[j] - nums[minIndex] >= valueDifference) {
                return {minIndex, j};
            }
            if (nums[maxIndex] - nums[j] >= valueDifference) {
                return {maxIndex, j};
            }
        }
        return {-1, -1};
    }
};