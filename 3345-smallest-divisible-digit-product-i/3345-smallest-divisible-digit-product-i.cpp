class Solution {
public:
    int digitProduct(int x) {
        int prod = 1;
        while (x > 0) {
            prod *= (x % 10);
            x /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            int prod = digitProduct(n);
            if (prod % t == 0)
                return n;
            n++;
        }
        return -1;
    }
};