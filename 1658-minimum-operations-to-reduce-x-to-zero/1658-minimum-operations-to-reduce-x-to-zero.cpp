class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = 0 ;
        for( int i = 0 ; i < nums.size() ; i++){
            totalsum +=nums[i];
        }
        int target = totalsum - x;
        if( target < 0 ){
            return -1;
        }
        if( target == totalsum){
            return nums.size();
        }
        int left = 0;
        int maxlen = -1;
        int currsum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            currsum += nums[i];
            while(currsum > target){
                currsum -= nums[left];
                left++;
            }
            if(currsum == target){
                maxlen = max(maxlen , i - left +1);
            }
        }
        if(maxlen == -1){
            return -1;
        }
        return nums.size() - maxlen;
    }
};