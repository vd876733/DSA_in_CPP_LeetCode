class Solution {
public:
    using ll = long long;
    ll mod = 1e9+7;
    ll pos(vector<int> & alpha , int k){ // O(5000)
        vector<ll> m;
        ll n =0;
        for(int i : alpha){
            n+=i;
            if(i>=1){
                m.push_back(i);
            }
        }

        ll num =1 ,add=1;
        for(ll i : m){
            for(ll j = 1 ; j<=i; j++){
                num = (num *add);
                add++;
                num/=j;
                if(num >=k){
                    return k;
                }
            }
        }
        return num;
    }
    string smallestPalindrome(string s, int k) {
        string temp ;
        int n = s.length();
        vector<int> alpha(26,0);
        for(int i =0 ; i <n/2 ; i++ ){
            temp.push_back(s[i]);
            alpha[s[i]-'a']++;
        }
        sort(temp.begin(),temp.end());
        
        string res;
        ll tot =0;
        for(int i = 0 ;i < n/2; i++ ){ // O(n*n)
            bool ok = true;
            for(int j =0 ; j<26 ; j++ ){
                if(alpha[j]!=0){
                    alpha[j]--; // if kept
                    int val = pos(alpha,k);
                    tot += val; // then add this
                    alpha[j]++; // back step
                    //cout<<"tot: "<<tot<<" ";
                    if(tot >=k){
                        alpha[j]--;
                        tot -= val;
                        res.push_back(j+'a');
                        ok = false;
                        //cout<<"done"<<endl;
                        break;
                    }
                    //else tot -=val;
                }
            }
            //cout<<endl;
            
            if(ok){
                //cout<<"i: "<<i<<endl;
                return "";
            }
            //cout<<"res: "<<res<<endl;
            
        }
        //if(res.empty)return res;
        string t =res;
        reverse(t.begin(),t.end());
        if(n&1){
            res.push_back(s[(n)/2]);
        }
        res +=t;
        return res;
    }
};