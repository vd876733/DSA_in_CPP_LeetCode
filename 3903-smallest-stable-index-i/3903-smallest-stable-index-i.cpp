class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        vector<int> maxa;

        for( int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
            maxa.push_back(maxi);
        }
        int mini = INT_MAX;
        vector<int> mina(nums.size());

        for( int i = nums.size()-1 ; i >=0 ; i--){
            mini = min(mini , nums[i]);
            mina[i] = mini;
        }
        int minii = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            int sscore = maxa[i] - mina[i];
            if(sscore <= k){
                return i;
            }
        }
        return -1;
        
    }
};