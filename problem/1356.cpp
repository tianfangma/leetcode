by tianfangma
class Solution {
public:
    int toBinary(int num)
    {
        int res=0;
        while(num>0)
        {
            if(num%2==1)
            {
                res+=1;
            }
            num/=2;
        }
        return res;
    }
    static bool cmp(const pair<int,int>&p1,const pair<int,int>&p2)
    {
        if(p1.second!=p2.second)
        {
            return p1.second<p2.second;
        }
        else
        {
            return p1.first<p2.first;
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vec;
        vector<int>res;

        for(int i=0;i<arr.size();++i)
        {
            vec.emplace_back(pair<int,int>(arr[i],toBinary(arr[i])));
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();++i)
        {
            res.emplace_back(vec[i].first);
        }
        return res;
    }
};
