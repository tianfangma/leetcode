//by tianfangma
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

//official question explanation 
class Solution {
public:
    int get(int x){
        int res = 0;
        while (x) {
            res += (x % 2);
            x /= 2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (auto x: arr) {
            bit[x] = get(x);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};

//bit calculator
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1;i <= 10000; ++i) {
            bit[i] = bit[i>>1] + (i & 1);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};
