class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> starts;
        for(int i=0;i<n;i++){
            starts.push_back({intervals[i][0],i});
        }
        sort(starts.begin(),starts.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int target=intervals[i][1];
            auto it=lower_bound(starts.begin(),starts.end(),make_pair(target,-1));
            if(it==starts.end())
                ans[i]=-1;
            else
                ans[i]=it->second;
        }
        return ans;
    }
};