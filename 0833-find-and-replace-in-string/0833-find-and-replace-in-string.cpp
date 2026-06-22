class Solution {
public:
    string findReplaceString(string s,vector<int>& indices,vector<string>& sources,vector<string>& targets) {
        int n = indices.size();
        vector<int> match(s.size(), -1);
        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            if (s.substr(idx, sources[i].size()) == sources[i]) {
                match[idx] = i;
            }
        }
        string ans;
        for (int i = 0; i < s.size();) {
            if (match[i] != -1) {
                int j = match[i];
                ans += targets[j];
                i += sources[j].size();
            }
            else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};