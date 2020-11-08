class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int res=0,min_price=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(res<prices[i]-min_price)
            {
                res=prices[i]-min_price;
            }
            if(prices[i]<min_price)
            {
                min_price=prices[i];
            }
        }
        return res;
    }
};
