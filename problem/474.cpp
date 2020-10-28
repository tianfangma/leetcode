/*
状态转移方程 dp[i][j]=max(1+dp[i-cost0][j-cost1],dp[i][j])
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]={0};
        for(const auto &str:strs)
        {
            int zero=findzeros(str);
            int one=str.length()-zero;
            for(int zeros=m;zeros>=zero;zeros--)
            {
                for(int ones=n;ones>=one;ones--)
                {
                    dp[zeros][ones]=max((1+dp[zeros-zero][ones-one]),dp[zeros][ones]);
                }
            }
        }
        return dp[m][n];
    }
    int findzeros(string str)
    {
        int cnt=0;
        for(int i=0;i<str.length();++i)
        {
            if(str[i]=='0')
            {
                cnt++;
            }
        }
        return cnt;
    }
};

