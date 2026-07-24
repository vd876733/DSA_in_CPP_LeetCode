class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string , int> mp;
        for( int i = 0 ; i < messages.size() ; i++){
            int w = 1;
            for( int j = 0 ; j < messages[i].size() ; j++){
                if(messages[i][j] == ' '){
                    w++;
                }
            }
            mp[senders[i]] += w;

        }
        string ans = "";
        int mx = 0;

        for (auto it : mp) {

            if (it.second > mx) {
                mx = it.second;
                ans = it.first;
            }
            else if (it.second == mx && it.first > ans) {
                ans = it.first;
            }
        }

        return ans;
    }
};