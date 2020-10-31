//violent edition
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();++i)
        {
            int temp=0;
            for(int j=0;j<nums.size();++j)
            {
                if(i!=j)
                {
                    if(nums[i]>nums[j])
                    {
                        ++temp;
                    }
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

//quick sort edition
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int>> vec;
        int n=nums.size();
        vector<int>res(n,0);
        for(int i=0;i<nums.size();++i)
        {
            vec.emplace_back(nums[i],i);
        }
        sort(vec.begin(),vec.end());
        int prev=-1;
        for(int i=0;i<nums.size();++i)
        {
            if(i==0||vec[i].first!=vec[i-1].first)
            {
                prev=i;
            }
            res[vec[i].second]=prev;
        }
        return res;
    }
};

//counting sort
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec(101,0);
        vector<int> res;
        for(int i=0;i<nums.size();++i)
        {
            vec[nums[i]]++;
        }
        for(int i=1;i<101;++i)
        {
            vec[i]+=vec[i-1];
        }
        for(int i=0;i<nums.size();++i)
        {
            res.emplace_back(nums[i]==0?0:vec[nums[i]-1]);
        }
        return res;
    }
};
