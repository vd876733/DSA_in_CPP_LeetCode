class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0 ;
        int s = 0;
        int mins = INT_MAX;
        for( int i = 0 ; i < nums.size() ; i++){
            s += nums[i];
            while( s >= target){
                mins = min( mins, i - l + 1);
                s -= nums[l];
                l++;
            }
        }
        if( mins == INT_MAX){
                return 0 ;
        }
        return mins;
    }
};