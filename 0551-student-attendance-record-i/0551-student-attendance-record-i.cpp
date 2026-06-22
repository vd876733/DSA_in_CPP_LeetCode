class Solution {
public:
    bool checkRecord(string s) {

        int absent = 0;
        int late = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'A') {
                absent++;
            }

            if(s[i] == 'L') {
                late++;
            }
            else {
                late = 0;
            }

            if(absent >= 2 || late >= 3) {
                return false;
            }
        }

        return true;
    }
};