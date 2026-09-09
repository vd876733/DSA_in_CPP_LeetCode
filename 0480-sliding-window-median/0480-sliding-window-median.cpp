class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> window;
        // Put first k elements into window
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }
        // Median position
        auto mid = next(window.begin(), (k - 1) / 2);
        for (int i = k; ; i++) {
            // Find median
            if (k % 2 == 1) {
                ans.push_back(*mid);
            }
            else {
                auto mid2 = next(mid);
                ans.push_back(
                    ((long long)*mid + *mid2) / 2.0
                );
            }
            // Finished
            if (i == nums.size()) {
                break;
            }
            // Add new element
            window.insert(nums[i]);

            // Adjust median iterator after insertion
            if (nums[i] < *mid) {
                mid--;
            }
            // Remove old element
            int old = nums[i - k];
            if (old <= *mid) {
                mid++;
            }
            window.erase(window.lower_bound(old));
        }
        return ans;
    }
};