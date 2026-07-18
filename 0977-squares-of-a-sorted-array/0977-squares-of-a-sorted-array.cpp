class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0 ;
        int r = nums.size() - 1;
        int i = nums.size() - 1;
        while( l <= r){
            int ln = nums[l] * nums[l];
            int rn = nums[r] * nums[r];
            if( ln > rn){
                ans[i] = ln;
                l++;
            }else{
                ans[i] = rn;
                r--;
            }
            i--;
        }
        return ans;
    }
};