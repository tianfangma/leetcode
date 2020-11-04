class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int left=newInterval[0],right=newInterval[1];
        bool placed=false;
        for(const auto& interval:intervals)
        {
            if(interval[0]>right)
            {
                //在插入区间左侧
                if(!placed)
                {
                    res.push_back({left,right});
                    placed=true;
                }
                res.emplace_back(interval);
            }
            else if(interval[1]<left)
            {
                //在插入区间右侧
                res.emplace_back(interval);
            }   
            else
            {
                //在插入区间中，寻找左右边界
                left=min(interval[0],left);
                right=max(interval[1],right);
            }
        }
        if(!placed)
        {
            res.push_back({left,right});
        }  
        return res;
    }
};
