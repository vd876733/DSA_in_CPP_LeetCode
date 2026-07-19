class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , vector<int>>,vector<pair<int , vector<int>>>,
        greater<pair<int , vector<int>>>> pq;
        vector<vector<int>> ans;
        for( int i = 0 ; i < points.size() ; i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            pq.push({d , points[i]});
        }
        
        for( int i = 0 ; i < k ; i++){
            vector<int> a = pq.top().second;
            pq.pop();
            ans.push_back(a);
        }
        return ans;
    }
};