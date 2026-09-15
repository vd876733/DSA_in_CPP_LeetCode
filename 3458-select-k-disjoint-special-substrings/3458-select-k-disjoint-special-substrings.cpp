class Solution {
public:
    bool maxSubstringLength(string s, int k) {

        if (k == 0)
            return true;

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < n; i++) {

            int x = s[i] - 'a';

            first[x] = min(first[x], i);
            last[x] = i;
        }

        vector<pair<int, int>> intervals;

        // Try every character as the start
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            // Expand the interval
            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // This character started before our interval
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of this character
                r = max(r, last[x]);
            }

            if (valid) {

                // Whole string itself is not allowed
                if (!(l == 0 && r == n - 1)) {
                    intervals.push_back({l, r});
                }
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        int count = 0;
        int lastEnd = -1;

        // Greedily select non-overlapping intervals
        for (auto interval : intervals) {

            int l = interval.first;
            int r = interval.second;

            if (l > lastEnd) {

                count++;
                lastEnd = r;

                if (count >= k)
                    return true;
            }
        }

        return false;
    }
};