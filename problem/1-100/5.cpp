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
