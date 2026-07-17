class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0 ;
        int sum = 0;
        int min_ans = INT_MAX;
        for( int i = 0 ; i < nums.size( ) ; i++){
            sum += nums[i];
            while(sum >= target){
                min_ans = min(min_ans , i - left + 1);
                sum -= nums[left];
                left++;
            }
            
        }
        if (min_ans == INT_MAX) {
            return 0;
        }
        return min_ans;
    }
};