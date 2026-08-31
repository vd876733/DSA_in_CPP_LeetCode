class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Direction of this starting point
            bool positive = nums[i] > 0;
            int slow = i;
            int fast = i;
            while (true) {
                // Slow next
                int nextSlow = nextIndex(nums, slow);
                // Direction changes
                if ((nums[nextSlow] > 0) != positive)
                    break;
                // Fast first move
                int nextFast = nextIndex(nums, fast);
                if ((nums[nextFast] > 0) != positive)
                    break;
                // Fast second move
                int nextFast2 = nextIndex(nums, nextFast);
                if ((nums[nextFast2] > 0) != positive)
                    break;
                slow = nextSlow;
                fast = nextFast2;
                // Cycle found
                if (slow == fast) {
                    // One-element cycle is invalid
                    if (slow == nextIndex(nums, slow))
                        break;
                    return true;
                }
            }
        }
        return false;
    }
};