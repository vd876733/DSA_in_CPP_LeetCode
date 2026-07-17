class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for( int i = 0;  i < nums.size() ;i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pq.push(make_pair(it.second,it.first));
        }
        vector<int> a;
        for( int i = 0 ; i < k ; i++){
            a.push_back(pq.top().second);
            pq.pop();
        }
        return a;

    }
};