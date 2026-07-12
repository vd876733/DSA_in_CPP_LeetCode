class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin() , a.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for( int i = 0 ; i< a.size() ; i++){
                if(mp.find(a[i]) == mp.end()){
                    mp[a[i]] = rank;
                    rank++;
                }
        }
        for (int i = 0; i < arr.size(); i++) {
                arr[i] = mp[arr[i]];
        }
        
        return arr;
    }
};