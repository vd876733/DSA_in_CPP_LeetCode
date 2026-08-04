class Solution {
public:
    vector<vector<int>> rects;
    vector<int> prefix;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int sum = 0;
        for(auto &r:rects){
            sum += (r[2]-r[0]+1)*(r[3]-r[1]+1);
            prefix.push_back(sum);
        }
    }
    vector<int> pick() {
        int total = prefix.back();
        int k = rand()%total + 1;
        int idx = lower_bound(prefix.begin(), prefix.end(), k)-prefix.begin();
        auto &r = rects[idx];
        int x = r[0] + rand()%(r[2]-r[0]+1);
        int y = r[1] + rand()%(r[3]-r[1]+1);
        return {x,y};
    }
};