class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> row;

        // Store reserved seats using bitmask
        for (auto &seat : reservedSeats) {
            int r = seat[0];
            int s = seat[1];

            row[r] |= (1 << (s - 1));
        }

        int ans = 0;

        // Rows with reservations
        for (auto &[r, mask] : row) {

            int left   = 0b0000011110; // seats 2-5
            int middle = 0b0001111000; // seats 4-7
            int right  = 0b0111100000; // seats 6-9

            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                ans += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                ans += 1;
            }
        }

        // Rows with no reservations
        // Each can fit 2 families
        ans += (n - row.size()) * 2;

        return ans;
    }
};