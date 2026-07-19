class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for( int i = 0 ; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if( f != s){
                pq.push( f - s);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();

    }
};