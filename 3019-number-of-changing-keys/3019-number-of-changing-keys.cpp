class Solution {
public:
    int countKeyChanges(string s) {
        int count=0,i=0,j=1,n=s.size();
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(j<n){
            if(s[i]!=s[j]){
                count++;
            }
        i++;
        j++;
        }
        return count;
    }
};