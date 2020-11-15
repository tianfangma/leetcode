//greedy, find the last number which is lager than the next one
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>stk;
        for(auto& x:num)
        {
            while(stk.size()>0&&stk.back()>x&&k)
            {
                stk.pop_back();
                k--;
            }
            stk.push_back(x);
        }
        for(;k>0;k--)
        {
            stk.pop_back();
        }
        string ans="";
        bool isLeadingZero = true;
        for(auto& x:stk)
        {
            if(isLeadingZero&&x=='0')
            {
                continue;
            }
            isLeadingZero = false;
            ans+=x;
        }
        return ans==""?"0":ans;
    }
};

