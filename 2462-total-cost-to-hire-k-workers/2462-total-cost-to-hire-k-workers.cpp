class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push(costs[left]);
            left++;
        }
        for (int i = 0; i < candidates && left <= right; i++) {
            rightHeap.push(costs[right]);
            right--;
        }
        long long ans = 0;
        while (k--) {
            if (rightHeap.empty() ||
                (!leftHeap.empty() && leftHeap.top() <= rightHeap.top())) {
                ans += leftHeap.top();
                leftHeap.pop();
                if (left <= right) {
                    leftHeap.push(costs[left]);
                    left++;
                }
            }
            else {
                ans += rightHeap.top();
                rightHeap.pop();
                if (left <= right) {
                    rightHeap.push(costs[right]);
                    right--;
                }
            }
        }
        return ans;
    }
};