class Solution {
public:
    using ll = long long ;
    vector<ll> all ;
    int getRank(ll val){
        return lower_bound(all.begin(), all.end(), val) - all.begin() + 1;
    }
    struct Fenewick {
        vector<ll>bit ;
        int n;
        Fenewick(int n) {
            this->n = n;
            bit.resize(n);
        }

        void add(int idx, int val) {
            while(idx < n) {
                bit[idx] += val;
                idx += (idx & -idx) ;
            }
        }

        ll query(int idx) {
            int sum =0 ;
            while(idx > 0) {
                sum += bit[idx];
                idx -= (idx & -idx) ;
            }
            return sum ;
        }

    };
    vector<int> resultArray(vector<int>& nums) {
        for(auto it : nums) all.push_back(it) ;
        sort(all.begin(), all.end()) ;
        all.erase(unique(all.begin(), all.end()), all.end()) ;
    
        int m = all.size() ;

        vector<int>arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size() ;
        Fenewick f1(m + 1), f2(m + 1) ;
        f1.add(getRank(nums[0]), 1) ;
        f2.add(getRank(nums[1]), 1) ;

        for(int i=2; i<n; i++) {
            int l1 = f1.query(getRank(nums[i])) ;
            l1 = arr1.size() - l1;
            int l2 = f2.query(getRank(nums[i])) ;
            l2 = arr2.size() - l2 ;

            if(l1 > l2) {
                arr1.push_back(nums[i]) ;
                f1.add(getRank(nums[i]), 1) ;
            }
            else if(l2 > l1) {
                arr2.push_back(nums[i]) ;
                f2.add(getRank(nums[i]), 1) ;
            }
            else {
                if(arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]) ;
                    f1.add(getRank(nums[i]), 1) ;
                }
                else {
                    arr2.push_back(nums[i]) ;
                    f2.add(getRank(nums[i]), 1) ;
                }
            }

        }

        vector<int> res(arr1.begin(), arr1.end()) ;
        for(int i : arr2) res.push_back(i);
        return res;

    }
};