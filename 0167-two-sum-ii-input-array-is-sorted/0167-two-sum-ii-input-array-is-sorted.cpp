class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
            int l = 0 ;
            int r = numbers.size() - 1;
            int sum = 0 ; 
            while( l < r){
                sum = numbers[l] + numbers[r];
                if( target > sum ){
                    l ++;
                }else if(target < sum){
                    r--;
                }
                if( sum == target){
                    return {l+1 , r+1};
                }
            }
            return {};
    }      
};