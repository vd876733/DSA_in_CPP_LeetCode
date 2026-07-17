class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zero = 0;
        int max_count = INT_MIN;
        for( int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                zero++;
            }
            while(zero > k){
                if(nums[left] == 0){
                    zero--;
                }
                left++;
            }
            max_count = max(max_count , i - left + 1);
        }
        return max_count;
    }
};