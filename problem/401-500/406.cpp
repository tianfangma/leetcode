//greedy algorithm
class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b)
    {
        if(a[1]!=b[1])
        {
            return a[1]<b[1];
        }
        else
        {
            return a[0]<b[0];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> res;
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<n;++i)
        {
            int temp=0;
            int j=0;
            for(;j<res.size();++j)
            {
                if(res[j][0]>=people[i][0])
                {
                    temp++;
                }
                if(temp>people[i][1])
                {
                    break;
                }
            }
            res.insert(res.begin()+j,people[i]);
        }
        return res;
    }
};
