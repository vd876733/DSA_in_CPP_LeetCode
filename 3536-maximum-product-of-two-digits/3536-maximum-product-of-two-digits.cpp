class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while( n > 0){
            int i = n % 10;
            ans.push_back(i);
            n = n / 10;
        }
        sort(ans.begin() , ans.end());

        return ans[ans.size() - 1]*ans[ans.size() - 2];
    }
};