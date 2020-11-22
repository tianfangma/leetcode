//by tianfangma 
//rubbish algorithm
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hashmap;
        int res = 0;
        int temp = 0;
        int last = 0;
        for(int i=0;i<s.size();++i)
        {
            auto it = hashmap.find(s[i]);
            if(it!=hashmap.end())
            {
                last = it->second;
                if(temp>res)
                {
                    res=temp;
                }
                hashmap.erase(hashmap.begin(),hashmap.end());
                i=last;
                temp = 0;
            }
            else
            {
                hashmap[s[i]]=i;
                temp++;
            }
        }
        if(temp>res)
        {
            res=temp;
        }
        return res;
    }
};

//sliding window
//leetcode solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for(int i=0;i<n;++i)
        {
            if(i!=0)
            {
                occ.erase(s[i-1]);
            }
            while(rk+1<n&&!occ.count(s[rk+1]))
            {
                occ.insert(s[rk+1]);
                rk++;
            }
            ans=max(ans,rk-i+1);
        }
        return ans;
    }
};
