class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = 1000000000;
        vector<int> best(n, INF);
        int left = 0;
        int sum = 0;
        int ans = INF;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int len = right - left + 1;
                // Previous subarray must end before left
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }
                // Best subarray ending at or before right
                if (right == 0) {
                    best[right] = len;
                } else {
                    best[right] = min(best[right - 1], len);
                }
            } else {
                // No new valid subarray ending at right
                if (right > 0) {
                    best[right] = best[right - 1];
                }
            }
        }
        if (ans == INF) {
            return -1;
        }
        return ans;
    }
};