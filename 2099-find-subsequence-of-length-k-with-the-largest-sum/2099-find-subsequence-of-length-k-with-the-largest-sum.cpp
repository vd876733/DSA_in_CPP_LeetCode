class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<pair<int,int>> v;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;
        });

        vector<pair<int,int>> temp;

        for (int i = 0; i < k; i++) {
            temp.push_back(v[i]);
        }

        sort(temp.begin(), temp.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        });

        vector<int> ans;

        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};