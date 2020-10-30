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

//dfs
class Solution {
public:
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>& grid,int n,int m)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==0)
        {
            return 1;
        }
        if(grid[i][j]==2)
        {
            return 0;
        }
        grid[i][j]=2;
        int res=0;
        for(int k=0;k<4;++k)
        {
            int tx=i+dir[k][0];
            int ty=j+dir[k][1];
            res+=dfs(tx,ty,grid,n,m);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1)
                {
                    ans+=dfs(i,j,grid,n,m);
                }
            }
        }
        return ans;
    }
};

//perimeter formula=4*岛屿数量-2*相邻岛屿数量
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int land = 0;
        int border = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]==1){
                    land++;
                    if (i<grid.size()-1&&grid[i+1][j]==1){
                        border++;
                    }
                    if (j<grid[0].size()-1&&grid[i][j+1]==1){
                        border++;
                    }
                }
            }

        }
        return land*4-border*2;
    }
};
