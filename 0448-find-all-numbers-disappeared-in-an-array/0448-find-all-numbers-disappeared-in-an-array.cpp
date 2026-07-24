class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int l = nums.size();
        unordered_map<int, int > mp;
        for( int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int n = l;
        vector<int> ans;
        for( int i = 1 ; i <= n ; i++){
            if(mp[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};