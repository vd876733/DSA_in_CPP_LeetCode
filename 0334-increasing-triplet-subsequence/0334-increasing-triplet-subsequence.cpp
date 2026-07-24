class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         int first = INT_MAX;
        int second = INT_MAX;

        for (int n : nums) {
            if (n <= first) {
                first = n;  // smallest so far
            } else if (n <= second) {
                second = n; // second smallest
            } else {
                // n > second → found a triplet
                return true;
            }
        }
        return false;
    }
};