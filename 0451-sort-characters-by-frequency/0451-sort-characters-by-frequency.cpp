class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for( int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int , char>> pq;
        for(auto it : mp){
            pq.push(make_pair(it.second,it.first));
        }
        string ans = "";
        while(!pq.empty()){
            int f = pq.top().first;
            int c = pq.top().second;
            pq.pop();
            for( int i = 0 ; i < f ; i++){
                ans += c;
            }
        }
        return ans;
    }
};