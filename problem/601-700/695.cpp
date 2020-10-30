//dfs
class Solution {
public:
    int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int x,int y,vector<vector<int>>& grid,int n,int m)
    {
        if(x<0||x>=n||y<0||y>=m||grid[x][y]==0||grid[x][y]==2)
        {
            return 0;
        }
        int res=1;
        grid[x][y]=2;
        for(int i=0;i<4;++i)
        {
            res+=dfs(x+arr[i][0],y+arr[i][1],grid,n,m);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    int temp=dfs(i,j,grid,n,m);
                    if(res<temp)
                    {
                        res=temp;
                    }       
                }
            }
        }
        return res;
    }
};
