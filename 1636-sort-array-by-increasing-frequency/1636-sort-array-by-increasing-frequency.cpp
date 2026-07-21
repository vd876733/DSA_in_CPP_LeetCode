class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (mp[a] == mp[b])
                return a > b;      
            return mp[a] < mp[b]; 
        });
        return nums;class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto it : mp) {
            pq.push({it.second, -it.first});
        }

        vector<int> ans;

        while (!pq.empty()) {

            int freq = pq.top().first;
            int val = -pq.top().second;
            pq.pop();

            for (int i = 0; i < freq; i++) {
                ans.push_back(val);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
    }
};