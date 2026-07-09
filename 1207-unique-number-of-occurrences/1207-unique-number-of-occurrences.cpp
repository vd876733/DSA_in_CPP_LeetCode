class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for( int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
            
        }
        vector<int> fq;
        for( auto f : mp){
            fq.push_back(f.second);
        }
        sort(fq.begin() , fq.end());
        for( int i = 0 ; i < fq.size()-1 ; i++){
            if(fq[i] == fq[i+1]) return false;
        }
        return true;
    }
};