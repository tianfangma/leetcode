/*
分成两种情况，1:偷第一家不偷最后一家；2偷最后一家不偷第一家
状态转移方程同198
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        else if(nums.size()==1)
        {
            return nums[0];
        }
        return max(robrob(0,nums.size()-1,nums),robrob(1,nums.size(),nums));
    }
    int robrob(int start,int end,vector<int>& nums)
    {
        int preMAX=0;
        int currentMAX=0;
        for(int i=start;i<end;++i)
        {
            int temp=currentMAX;
            currentMAX=max(preMAX+nums[i],currentMAX);
            preMAX=temp;
        }
        return max(currentMAX,preMAX);
    }
};
