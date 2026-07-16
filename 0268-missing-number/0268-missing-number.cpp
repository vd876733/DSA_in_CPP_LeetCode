class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for( int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int n = nums.size() + 1;
        while(n--){
            if(mp[n] == 0){
                return n;
            } 

        }
        return -1;
    }
};