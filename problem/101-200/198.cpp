/*
状态转移方程：dp[i]=max(dp[i-2]+nums[i],dp[i-1]),偷第i家，或者不偷第i家
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[1000]={0};
        if(nums.empty())
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();++i)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
