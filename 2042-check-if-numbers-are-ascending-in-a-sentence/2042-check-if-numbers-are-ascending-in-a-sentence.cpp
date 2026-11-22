class Solution {
public:
    bool areNumbersAscending(string s) 
    {
        int prev=-1;
        int temp=0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' '&& temp!=0) 
            {
                if(temp<=prev) return false;
                prev = temp;
                temp=0;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                temp=temp*10+(s[i]-'0');
            }
        }
        if(s[n-1]>='0'&&s[n-1]<='9')
        {
            if(temp<=prev) return false;
        } 
        return true;
    }
//please upvote...
};