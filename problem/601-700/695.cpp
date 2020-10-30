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

//dfs and stack
class Solution {
public:
    int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                int cur=0;
                stack<int> stkx;
                stack<int> stky;
                stkx.push(i);
                stky.push(j);
                while(!stkx.empty())
                {
                    int curx=stkx.top(),cury=stky.top();
                    stkx.pop();
                    stky.pop();
                    if(curx<0||curx>=grid.size()||cury<0||cury>=grid[0].size()||grid[curx][cury]!=1)
                    {
                        continue;
                    }
                    cur+=1;
                    grid[curx][cury]=2;
                    for(int k=0;k<4;++k)
                    {
                        int tx=curx+arr[k][0],ty=cury+arr[k][1];
                        stkx.push(tx);
                        stky.push(ty);
                    }
                }
                res=max(res,cur);
            }
        }
        return res;
    }
};
//bfs and queue
class Solution {
public:
    int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                int cur=0;
                queue<int> queX;
                queue<int> queY;
                queX.push(i);
                queY.push(j);
                while(!queX.empty())
                {
                    int curx=queX.front(),cury=queY.front();
                    queX.pop();
                    queY.pop();
                    if(curx<0||curx>=grid.size()||cury<0||cury>=grid[0].size()||grid[curx][cury]!=1)
                    {
                        continue;
                    }
                    cur+=1;
                    grid[curx][cury]=2;
                    for(int k=0;k<4;++k)
                    {
                        int tx=curx+arr[k][0],ty=cury+arr[k][1];
                        queX.push(tx);
                        queY.push(ty);
                    }
                }
                res=max(res,cur);
            }
        }
        return res;
    }
};
