class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         int first = INT_MAX;
        int second = INT_MAX;

        for (int n : nums) {
            if (n <= first) {
                first = n;  // smallest so far
            } else if (n <= second) {
                second = n; // second smallest
            } else {
                // n > second → found a triplet
                return true;
            }
        }
        return false;
    }
};

// for( int j = 1 ; j < nums.size() ; j++)
//             if( nums[j-1] < nums[j]){
//                 if(nums[j] < nums[i] ){
//                     return true;
//                     break;
//                 }
//             }else{
//                 i++;
                
//             }
//         }
//         return false;