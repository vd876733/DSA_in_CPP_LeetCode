class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int num : nums) {
            v.push_back(to_string(num));
        }
        sort(v.begin(), v.end(), [](string a, string b) {
            return a + b > b + a;
        });

        string ans = "";

        for (string s : v) {
            ans += s;
        }

        // Handle [0, 0]
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};