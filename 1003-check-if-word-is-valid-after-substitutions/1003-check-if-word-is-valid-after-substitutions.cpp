class Solution {
public:
    bool doesItMatch(char ch1, char ch2, char ch3) {

        if (ch1 == 'a' && ch2 == 'b' && ch3 == 'c')
            return true;
        else
            return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (st.size() >= 2) {
                char ch2 = st.top();
                st.pop();
                char ch1 = st.top();
                st.pop();
                if (doesItMatch(ch1, ch2, s[i]))
                    continue;
                else {
                    st.push(ch1); // push ch1 before ch2 maintaining   order
                    st.push(ch2);
                    st.push(s[i]);
                }
            }

            else
                st.push(s[i]);
        }

        if (!st.empty())
            return false;
        else
            return true;
    }
};