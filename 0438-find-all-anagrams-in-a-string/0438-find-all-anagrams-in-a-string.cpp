class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()){
            return {};
        }
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        vector<int> a;
        for( int i = 0 ; i < p.size() ; i++){
            mp1[s[i]]++;
            mp2[p[i]]++;
        }
        if( mp1 == mp2){
            a.push_back(0);
        }
        for( int i = p.size() ; i < s.size() ; i++){
            mp1[s[i]]++;
            mp1[s[i - p.size()]]--;
            if(mp1[s[i-p.size()]] == 0){
                mp1.erase(s[i-p.size()]);
            }
            if(mp1 == mp2){
                a.push_back(i - p.size() + 1);
            }
        }
        return a;
    }
};
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         if (p.size() > s.size()) {
//             return {};
//         }
//         sort(p.begin(), p.end());
//         string ans = "";
//         for (int i = 0; i < p.size(); i++) {
//             ans += s[i];
//         }
//         vector<int> a;
//         for (int i = p.size(); i <= s.size(); i++) {
//             string temp = ans;
//             sort(temp.begin(), temp.end());
//             if (temp == p) {
//                 a.push_back(i - p.size());
//             }
//             if (i == s.size()) {
//                 break;
//             }
//             ans.erase(ans.begin());
//             ans += s[i];
//         }
//         return a;
//     }
// };