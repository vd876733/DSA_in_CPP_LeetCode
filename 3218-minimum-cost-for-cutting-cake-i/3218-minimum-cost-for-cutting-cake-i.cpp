class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut,
                          vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int i = 0;
        int j = 0;
        long long ans = 0;
        long long horizontalPieces = 1;
        long long verticalPieces = 1;
        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                ans += 1LL * horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                ans += 1LL * verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }
        while (i < horizontalCut.size()) {
            ans += 1LL * horizontalCut[i] * verticalPieces;
            i++;
        }
        while (j < verticalCut.size()) {
            ans += 1LL * verticalCut[j] * horizontalPieces;
            j++;
        }
        return ans;
    }
};