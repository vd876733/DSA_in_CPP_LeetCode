class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({w, v});
        }

        vector<int> weights(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        weights[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (weight > weights[node])
                continue;

            for (auto& [neighbourWeight, neighbourNode] : adj[node]) {
                if (weight + neighbourWeight < weights[neighbourNode]) {
                    weights[neighbourNode] = weight + neighbourWeight;
                    pq.push({weight + neighbourWeight, neighbourNode});
                }
            }
        }

        int maxTime = 0;

        for (int i = 1; i <= n; i++) {
            if (weights[i] == INT_MAX)
                return -1;

            maxTime = max(maxTime, weights[i]);
        }

        return maxTime;
    }
};