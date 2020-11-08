class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }

        int n=prices.size();
        int f0=-prices[0];//持有股票
        int f1=0;//无股票，处于冷冻期
        int f2=0;//无股票，不处于冷冻期
        for(int i=1;i<n;++i)
        {
            int newf0=max(f0,f2-prices[i]);
            int newf1=f0+prices[i];
            int newf2=max(f1,f2);
            f0=newf0;
            f1=newf1;
            f2=newf2;
        }
        return max(f1,f2);
    }
};
