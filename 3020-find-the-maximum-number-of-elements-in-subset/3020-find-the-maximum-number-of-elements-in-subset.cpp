class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int ans = 1;
        if(mp.count(1)) {
            int cnt = mp[1];
            if(cnt % 2 == 0)
                cnt--;
            ans = max(ans, cnt);
        }
        for(auto it : mp) {
            long long x = it.first;
            if(x == 1)
                continue;
            int len = 0;
            long long cur = x;
            while(mp.count(cur)) {
                if(mp[cur] >= 2) {
                    len += 2;
                    cur = cur * cur;
                }
                else {
                    len += 1;
                    break;
                }
                if(cur > 1e18)
                    break;
            }
            if(len % 2 == 0)
                len--;
            ans = max(ans, len);
        }
        return ans;
    }
};