//by tianfangma
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>::iterator it = nums.begin();
        for(int i=0;i<n;++i)
        {
            if(*it==0)
            {
                nums.erase(it);
                nums.push_back(0);
            }
            else
                ++it;
        }
    }
};

//two pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),left=0,right=0;
        while(right<n)
        {
            if(nums[right])//找到右边第一个非零数
            {
                swap(nums[left],nums[right]);
                left++;//指向处理好队列的尾部
            }
            right++;
        }
    }
};
