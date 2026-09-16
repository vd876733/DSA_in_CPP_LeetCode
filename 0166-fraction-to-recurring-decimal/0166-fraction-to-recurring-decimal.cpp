class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Handle zero
        if (numerator == 0) {
            return "0";
        }
        string ans = "";
        // Check negative result
        if ((numerator < 0) != (denominator < 0)) {
            ans += "-";
        }
        // Use long long to avoid overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);
        // Add integer part
        ans += to_string(num / den);
        // Get remainder
        long long rem = num % den;
        // No decimal part
        if (rem == 0) {
            return ans;
        }
        ans += ".";
        unordered_map<long long, int> mp;
        while (rem != 0) {
            // Remainder already appeared
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }
            // Store position of this remainder
            mp[rem] = ans.size();
            // Multiply remainder by 10
            rem *= 10;
            // Get next digit
            ans += to_string(rem / den);
            // Get new remainder
            rem %= den;
        }
        return ans;
    }
};