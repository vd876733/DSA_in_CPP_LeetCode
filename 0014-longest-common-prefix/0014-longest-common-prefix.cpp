class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        for( int i = 1 ; i < strs.size() ; i++){
                while( strs[i].find(pre) != 0){
                    pre.pop_back();
                }
        }
        return pre;
    }
};