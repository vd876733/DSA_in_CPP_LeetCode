class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                count++;
            else
                count--;

            if (count == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inside) + "0");
                start = i + 1;
            }
        }
        sort(parts.begin(), parts.end(), greater<string>());
        string ans = "";
        for (string x : parts)
            ans += x;
        return ans;
    }
};