class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int lo = -1;
        int lt = -1;
        int ans = INT_MAX;
        for( int i = 0 ; i< nums.size() ; i++){
            if( nums[i] == 1){
                if(lt != -1){
                    ans = min(ans , i - lt);
                }
                lo = i;
            }else if(nums[i] == 2){
                if(lo != -1){
                    ans = min (ans , i - lo);
                }
                lt = i;
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};