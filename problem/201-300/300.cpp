/*
状态转移方程：dp[i]=max(dp[j])+1,且nums[i]>nums[j]
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int *dp=new int[nums.size()];
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            dp[i]=1;
            for(int j=0;j<i;++j)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
