class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(int i = 0; i < num.size(); i++) {
            while(!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k > 0) {
            st.pop_back();
            k--;
        }
        string ans;
        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }
        while(i < st.size()) {
            ans.push_back(st[i]);
            i++;
        }
        if(ans.empty()) {
            return "0";
        }
        return ans;
    }
};