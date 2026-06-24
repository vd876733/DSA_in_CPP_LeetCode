class Solution {
public:
    string removeDigit(string number, char digit) {
        int pos = -1;
        for(int i = 0; i < number.size(); i++) {
            if(number[i] == digit) {
                pos = i;
                if(i + 1 < number.size() &&
                   number[i] < number[i + 1]) {
                    break;
                }
            }
        }
        number.erase(pos, 1);
        return number;
    }
};