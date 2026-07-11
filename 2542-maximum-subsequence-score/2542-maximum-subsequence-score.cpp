class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }
        sort(vp.rbegin(), vp.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += vp[i].second;
            pq.push(vp[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, sum * 1LL * vp[i].first);
            }
        }
        return ans;
    }
};