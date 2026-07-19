class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for( int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int ,int >> pq;
        for( auto it : mp){
            pq.push(make_pair(it.second , it.first));
        }
        vector<int> ans(k);
        for( int i = 0 ; i < k ; i++){
            int s = pq.top().second;
            pq.pop();
            ans[i] = s;
        }
        return ans;
    }
};