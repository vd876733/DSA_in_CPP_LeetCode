class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        long long ans = 0;
        while( l < r){
            string a = to_string(nums[l]);
            string b = to_string(nums[r]);

            ans += stoll(a + b);

            l++;
            r--;
        }
        if (l == r) {
            ans += nums[l];
        }
        return  ans ;
    }
};