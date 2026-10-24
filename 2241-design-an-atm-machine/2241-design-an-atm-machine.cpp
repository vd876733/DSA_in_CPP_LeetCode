class ATM {
public:
    vector<int> totalcount = {0, 0, 0, 0, 0};
    ATM() { 

    }
    
    void deposit(vector<int> banknotesCount) 
    {
        for(int i=0;i<banknotesCount.size();i++)
        {
            if(banknotesCount[i]>0)
            {
                totalcount[i]+=banknotesCount[i];
            }
        }
        return ;
    }
    
    vector<int> withdraw(int amount) 
    {
        vector<int>ans(5,0);
        vector<int>notes={20,50,100,200,500};
        for(int i=4;i>=0;i--)
        {
            ans[i]=min((amount / notes[i]), totalcount[i]); 
            amount-=ans[i]*notes[i];
        }
        if(amount==0)
        {
            for(int i=0;i<=4;i++)
            {
                totalcount[i]-=ans[i];
            }
            return ans;
        }
        return{-1};
    }
};
//please upvote...
/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */