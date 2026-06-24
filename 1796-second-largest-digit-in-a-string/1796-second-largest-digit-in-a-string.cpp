class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int secondLargest = -1;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                int d = s[i] - '0';
                if(d > largest) {
                    secondLargest = largest;
                    largest = d;
                }
                else if(d < largest &&
                        d > secondLargest) {
                    secondLargest = d;
                }
            }
        }
        return secondLargest;
    }
};