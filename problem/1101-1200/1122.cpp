//too slow, by tianfangma
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>res;
        unordered_map<int,int> um;
        vector<int>temp;
        for(int i=0;i<arr1.size();++i)
        {
            um[arr1[i]]+=1;
            if(count(arr2.begin(),arr2.end(),arr1[i])==0)
            {
                temp.emplace_back(arr1[i]);
            }
        }
        for(int i=0;i<arr2.size();++i)
        {
            for(int j=0;j<um[arr2[i]];++j)
            {
                res.emplace_back(arr2[i]);
            }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();++i)
        {
            res.emplace_back(temp[i]);
        }
        return res;
    }
};

//custom sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>pos;
        for(int i=0;i<arr2.size();++i)
        {
            pos[arr2[i]]=i;
        }
        sort(arr1.begin(),arr1.end(),[&](int x,int y)
        {
            if(pos.count(x))
            {
                return pos.count(y)?pos[x]<pos[y]:true;
            }
            else
            {
                return pos.count(y)?false:x<y;
            }
        });
        return arr1;
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>pos;
        for(int i=0;i<arr2.size();++i)
        {
            pos[arr2[i]]=i;
        }
        auto mycmp=[&](int x)->pair<int,int>{
            return pos.count(x)?pair{0,pos[x]}:pair{1,x};
        };
        sort(arr1.begin(),arr1.end(),[&](int x,int y)
        {
            return mycmp(x)<mycmp(y);
        });
        return arr1;
    }
};

//use i-n and x replace (0,i)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>pos;
        int n=arr2.size();
        for(int i=0;i<n;++i)
        {
            pos[arr2[i]]=i-n;
        }
        sort(arr1.begin(),arr1.end(),[&](int x,int y)
        {
            return (pos.count(x)?pos[x]:x)<(pos.count(y)?pos[y]:y);
        });
        return arr1;
    }
};

//count sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int upper=*max_element(arr1.begin(),arr1.end());
        vector<int>frequency(upper+1);
        for(int x:arr1)
        {
            ++frequency[x];
        }
        vector<int>res;
        for(int x:arr2){
            for(int i=0;i<frequency[x];++i){
                res.push_back(x);
            }
            frequency[x]=0;
        }
        for(int x=0;x<=upper;++x){
            for(int i=0;i<frequency[x];++i){
                res.push_back(x);
            }
        }
        return res;
    }
};
