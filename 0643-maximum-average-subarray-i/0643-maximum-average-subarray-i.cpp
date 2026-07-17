class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0;
        
        for( int i = 0 ; i < k ; i++){
            sum+= nums[i];
            
        }
        double max_average =  (double)sum / k;
        for( int i = k ; i < nums.size() ; i++){
            sum = sum - nums[i-k] + nums[i];
            double average = (double)sum / k;
            max_average = max( max_average , average);
        }
        return max_average;
    }
};