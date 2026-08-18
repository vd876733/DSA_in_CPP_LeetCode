class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDelete = arr[0];
        int oneDelete = arr[0];

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int x = arr[i];

            int newNoDelete = max(x, noDelete + x);

            int newOneDelete = max({
                x,
                oneDelete + x,
                noDelete
            });

            noDelete = newNoDelete;
            oneDelete = newOneDelete;

            ans = max(ans, oneDelete);
        }

        return ans;
    }
};