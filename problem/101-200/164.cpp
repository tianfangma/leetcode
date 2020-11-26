//不讲武德 sort
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=1;i<n;++i)
        {
            res=max(res,nums[i]-nums[i-1]);
        }
        return res;
    }
};

//base number sorting
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        int maxElement=*max_element(nums.begin(),nums.end());
        int exp=1;
        vector<int> buf(n);
        while(maxElement>=exp)
        {
            vector<int> bucket(10,0);
            //统计
            for(int i=0;i<n;++i)
            {
                int digit = (nums[i]/exp)%10;
                bucket[digit]++;
            }
            //排序
            for(int i=1;i<10;++i)
            {
                bucket[i]+=bucket[i-1];
            }
            //整体排序
            for(int i=n-1;i>=0;--i)
            {
                int digit=(nums[i]/exp)%10;
                buf[bucket[digit]-1]=nums[i];
                bucket[digit]--;
            }
            copy(buf.begin(),buf.end(),nums.begin());
            exp*=10;
        }
        int res=0;
        for(int i=1;i<n;++i)
        {
            res=max(res,nums[i]-nums[i-1]);
        }
        return res;
    }
};

//bucket sorting
//leetcode solution
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;

        vector<pair<int, int>> bucket(bucketSize, {-1, -1});  // 存储 (桶内最小值，桶内最大值) 对，(-1, -1) 表示该桶是空的
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }

        int ret = 0;
        int prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (prev != -1) {
                ret = max(ret, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ret;
    }
};
