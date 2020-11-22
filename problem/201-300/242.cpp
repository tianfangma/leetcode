//by tianfangma
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!=t[i])
            {
                return false;
            }
        }
        return true;
    }
};

//hash map
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        vector<int> map(26,0);
        for(auto&i : s)
        {
            map[i-'a']++;
        }
        for(auto&i : t)
        {
            map[i-'a']--;
        }
        for(int i=0;i<26;++i)
        {
            if(map[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
