//state transfer equation: dp[i]=dp[j]&&check(s[j...i-1])


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto word_dict_set = unordered_set<string>();
        for(auto word : wordDict)
        {
            word_dict_set.insert(word);
        }

        auto dp = vector<bool>(s.size()+1);
        dp[0]=true;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(dp[j]&&word_dict_set.find(s.substr(j,i-j))!=word_dict_set.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

//use min,max to optimize
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto word_dict_set = unordered_set<string>();
        int min_size=INT_MAX,max_size=0;
        for(auto word : wordDict)
        {
            word_dict_set.insert(word);
            if(min_size>word.size()) min_size=word.size();
            if(max_size<word.size()) max_size=word.size();
        }

        auto dp = vector<bool>(s.size()+1);
        dp[0]=true;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=max(0,i-max_size);i-j>=min_size;++j)
            {
                if(dp[j]&&word_dict_set.find(s.substr(j,i-j))!=word_dict_set.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
