//iteration
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int len=grid.size();
        int width=grid[0].size();
        for(int i=0;i<len;++i)
        {
            for(int j=0;j<width;++j)
            {
                if(grid[i][j]==1)
                {
                    ans+=4;
                    for(int k=0;k<4;++k)
                    {
                        if(i-arr[k][0]>=0&&i-arr[k][0]<len&&j-arr[k][1]>=0&&j-arr[k][1]<width)
                        {
                            if(grid[i-arr[k][0]][j-arr[k][1]]==1)
                            {
                                ans-=1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
