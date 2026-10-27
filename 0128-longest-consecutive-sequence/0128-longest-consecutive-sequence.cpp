class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0 ;
        }
        sort(nums.begin() , nums.end());
        int c = 1;
        int mc = 1;
        for( int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if( nums[i] - nums[i-1] == 1){
                c++;
            }else{
                c = 1;
            }
            mc = max( mc , c);
        }
        return mc;
    }
};