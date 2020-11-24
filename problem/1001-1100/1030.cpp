//sort
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                res.push_back({i,j});
            }
        }
        sort(res.begin(),res.end(),[&](const vector<int>&a,const vector<int>&b){
            return abs(a[0]-r0)+abs(a[1]-c0)<abs(b[0]-r0)+abs(b[1]-c0);
        });
        return res;
    }
};

//bucket sort
class Solution {
public:
    int dist(int r1,int c1,int r0,int c0)
    {
        return abs(r1-r0)+abs(c1-c0);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist=max(r0,R-r0-1)+max(c0,C-c0-1);
        vector<vector<vector<int>>>bucket(maxDist+1);
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                int d=dist(i,j,r0,c0);
                bucket[d].push_back({i,j});
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<=maxDist;++i)
        {
            for(auto& x:bucket[i])
            {
                res.push_back(x);
            }
        }
        return res;
    }
};

//geometric method
//by leetcode solution
class Solution {
public:
    const int dr[4] = {1, 1, -1, -1};
    const int dc[4] = {1, -1, -1, 1};

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<int>> ret;
        int row = r0, col = c0;
        ret.push_back({row, col});
        for (int dist = 1; dist <= maxDist; dist++) {
            row--;
            for (int i = 0; i < 4; i++) {
                while ((i % 2 == 0 && row != r0) || (i % 2 != 0 && col != c0)) {
                    if (row >= 0 && row < R && col >= 0 && col < C) {
                        ret.push_back({row, col});
                    }
                    row += dr[i];
                    col += dc[i];
                }
            }
        }
        return ret;
    }
};

