//by tianfangma
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&p1,const pair<int,int>&p2)
        {
            return (p1.first*p1.first+p1.second*p1.second)<(p2.first*p2.first+p2.second*p2.second);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        vector<pair<int,int>> vp;
        for(int i=0;i<points.size();++i)
        {
            vp.push_back(pair<int,int>(points[i][0],points[i][1]));
            if(i<K)
            {
                res.push_back(vector<int>());
            }
        }
        sort(vp.begin(),vp.end(),cmp());
        vector<pair<int,int>>::iterator it=vp.begin();
        for(int i=0;i<K;++i)
        {
            res[i].push_back(it->first);
            res[i].push_back(it->second);
            it++;
        }
        return res;
    }
};

//sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        });
        return {points.begin(), points.begin() + K};
    }
};

//priority_queue
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,int>> q;
        for(int i=0;i<K;++i)
        {
            q.emplace(points[i][0]*points[i][0]+points[i][1]*points[i][1],i);
        }
        for(int i=K;i<points.size();++i)
        {
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(dist<q.top().first)
            {
                q.pop();
                q.emplace(dist,i);
            }
        }
        vector<vector<int>> res;
        while(!q.empty())
        {
            res.emplace_back(points[q.top().second]);
            q.pop();
        }
        return res;
    }
};

//quick_sort
class Solution {
private:
    mt19937 gen{random_device{}()};

public:
    void random_select(vector<vector<int>>& points, int left, int right, int K) {
        int pivot_id = uniform_int_distribution<int>{left, right}(gen);
        int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
        swap(points[right], points[pivot_id]);
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivot) {
                ++i;
                swap(points[i], points[j]);
            }
        }
        ++i;
        swap(points[i], points[right]);
        // [left, i-1] 都小于等于 pivot, [i+1, right] 都大于 pivot
        if (K < i - left + 1) {
            random_select(points, left, i - 1, K);
        }
        else if (K > i - left + 1) {
            random_select(points, i + 1, right, K - (i - left + 1));
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        random_select(points, 0, n - 1, K);
        return {points.begin(), points.begin() + K};
    }
};
