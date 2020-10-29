//不分治了 太菜了不会

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0;
        int maxAns=nums[0];
        for(int i = 0;i<nums.size();++i)
        {
            pre+=nums[i];
            maxAns=max(maxAns,pre);
            if(pre<0)
                pre=0;
        }
        return maxAns;
    }
};
