//center expansion
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int index=0, begin = 0, maxLen=0;
        while(index<n)
        {
            int left=index,right=index;
            while(right<n&&s[right]==s[right+1])
            {
                right++;
            }
            while(right<n&&left>=0&&s[left]==s[right])
            {
                left--;
                right++;
            }
            left++;
            right--;
            if(maxLen<right-left+1)
            {
                begin=left;
                maxLen=right-left+1;
            }
            index++;
        }
        return s.substr(begin,maxLen);
    }
};

//leetcode solution

//dynamic planning
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res;
        vector<vector<int>>dp(n,vector<int>(n));
        for(int l=0;l<n;++l)
        {
            for(int i=0;i+l<n;++i)
            {
                int j=i+l;
                if(l==0)
                {
                    dp[i][j]=1;
                }
                else if(l==1)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else
                {
                    dp[i][j]=(dp[i+1][j-1]&&s[i]==s[j]);
                }
                if(dp[i][j]&&l+1>res.size())
                {
                    res=s.substr(i,l+1);
                }
            }
        }
        return res;
    }
};

//center expansion

//manarcher
