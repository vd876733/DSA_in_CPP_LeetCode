class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word;
        string ans = "";
        while (ss >> word) {
            bool valid = true;
            if (word[0] != '$' || word.size() == 1){
                valid = false;
            }
            for (int i = 1; i < word.size() && valid; i++) {
                if (!isdigit(word[i]))
                    valid = false;
            }
            if (valid) {
                long long value = stoll(word.substr(1));
                double price = value * (100 - discount) / 100.0;
                ostringstream out;
                out << "$" << fixed << setprecision(2) << price;
                ans += out.str();
            } else {
                ans += word;
            }
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};