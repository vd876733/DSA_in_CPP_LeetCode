class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq;
        deque<int> mindq;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < nums.size(); right++) {
            while(!maxdq.empty() &&
                  nums[maxdq.back()] < nums[right]) {

                maxdq.pop_back();
            }
            maxdq.push_back(right);
            while(!mindq.empty() &&
                  nums[mindq.back()] > nums[right]) {
                mindq.pop_back();
            }
            mindq.push_back(right);
            while(nums[maxdq.front()] - nums[mindq.front()] > limit) {
                if(maxdq.front() == left) {
                    maxdq.pop_front();
                }
                if(mindq.front() == left) {
                    mindq.pop_front();
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};