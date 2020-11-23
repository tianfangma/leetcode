//by tianfangma
//greedy algorithm
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[=](const auto&a,const auto&b){
            if(a[0]==b[0])
            {
                return a[1]>b[1];
            }
            else
            {
                return a[0]<b[0];
            }
        });
        int res = 0;
        int left = 0,right = 0;
        for(int i=0;i<points.size();++i)
        {
            if(points[i][0]>right||i==0)
            { 
                left=points[i][0];
                right=points[i][1];
                res++;
            }
            else
            {
                if(points[i][0]>left)
                {
                    left=points[i][0];
                }
                if(points[i][1]<right)
                {
                    right=points[i][1];
                }
            }
        }
        return res;
    }
};
