//by tianfangma
class Solution {
public:
    string sortString(string s) {
        string res;
        unordered_map<char,int> charMap;
        for(int i=0;i<s.size();++i)
        {
            charMap[s[i]]++;
        }
        while(!charMap.empty())
        {
            for(char ch = 'a';ch<='z';++ch)
            {
                if(charMap[ch])
                {
                    res.insert(res.end(),1,ch);
                    charMap[ch]--;
                }
                if(charMap[ch]==0)
                {
                    charMap.erase(ch);
                }
            }
            for(char ch = 'z';ch>='a';--ch)
            {
                if(charMap[ch])
                {
                    res.insert(res.end(),1,ch);
                    charMap[ch]--;
                }
                if(charMap[ch]==0)
                {
                    charMap.erase(ch);
                }
            }
        }
        return res;
    }
};

//leetcode solution
class Solution {
public:
    string sortString(string s) {
        string res;
        vector<int>num(26);
        for(auto&ch:s)
        {
            num[ch-'a']++;
        }
        while(res.size()<s.size())
        {
            for(int i=0;i<26;++i)
            {
                if(num[i])
                {
                    res.push_back(i+'a');
                    num[i]--;
                }
            }
            for(int i=25;i>=0;--i) 
            {
                if(num[i])
                {
                    res.push_back(i+'a');
                    num[i]--;
                }
            }
        }
        return res;
    }
};
