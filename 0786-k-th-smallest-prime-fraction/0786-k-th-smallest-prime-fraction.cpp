class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int,int>>,vector<pair<double, pair<int,int>>>,
greater<pair<double, pair<int,int>>>> pq;
        // push arr[0]/arr[j]
        for(int j = 1; j < n; j++) {
            pq.push({
                (double)arr[0] / arr[j],
                {0, j}
            });
        }
        while(--k) {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            // move numerator forward
            if(i + 1 < j) {
                pq.push({(double)arr[i + 1] / arr[j],{i + 1, j}});
            }
        }
        auto ans = pq.top();
        int i = ans.second.first;
        int j = ans.second.second;
        return {arr[i], arr[j]};
    }
};