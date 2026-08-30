class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<pair<int , int >> v;
        for( int i = 0 ; i  < nums.size() ; i++){
                v.push_back({nums[i] , i});
        }
        sort(v.begin(), v.end());

        int small_i = v[0].second;
        int big_i = v[nums.size()-1].second;
        int l = min(small_i , big_i);
        int r = max(small_i , big_i);
        int n = nums.size();
        int front = r + 1;
        int back = n - l;
        int both = (l+1) + (n - r);
        return min({front , back , both});


    }
};