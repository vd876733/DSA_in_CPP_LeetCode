class Cashier {
public:
    unordered_map<int,int> mp;
    int n;
    int discount;
    int customer;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        customer = 0;
        for(int i = 0; i < products.size(); i++) {
            mp[products[i]] = prices[i];
        }
    }
    double getBill(vector<int> product, vector<int> amount) {
        customer++;
        double total = 0;
        for(int i = 0; i < product.size(); i++) {
            total += mp[product[i]] * amount[i];
        }
        if(customer % n == 0) {
            total *= (100 - discount);
            total /= 100.0;
        }
        return total;
    }
};