// 2020.10.28
// written by tianfang

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool res = false;
        unordered_map<int,int> m;
        for(const auto &x:arr)
        {
            m[x]++;
        }
        unordered_set<int>times;
        for(const auto &x:m)
        {
            times.insert(x.second);
        }
        if(times.size()==m.size())
        {
            res = true;
        }
        return res;
    }
};
