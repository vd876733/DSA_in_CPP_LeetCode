class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for( int i = 0 ; i <  nums.size() ; i++){
            mp[nums[i]]++;
        } 
        int mul = 1;
        for( int i = 1 ; ; i++){
            mul = k * i ;
            if(mp[mul] == 0){
                return mul;
            }
            
        }
    }
};