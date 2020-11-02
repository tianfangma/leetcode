//my edition
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;
        vector<int> res;
        for(int i=0;i<nums1.size();++i)
        {
            um[nums1[i]]=0;
        }
        for(int i=0;i<nums2.size();++i)
        {
            if(um.count(nums2[i]))
            {
                um[nums2[i]]++;
            }
        }
        unordered_map<int,int>::iterator iter;
        for(iter=um.begin();iter!=um.end();++iter)
        {
            if(iter->second>0)
            {
                res.emplace_back(iter->first);
            }
        }
        return res;
    }
};

//
