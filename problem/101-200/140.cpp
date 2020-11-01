//memory search
//backtrack

class Solution {
public:
private:
    unordered_map<int,vector<string>> res;
    unordered_set<string> word_set;
public:
    void backtrack(const string& s,int idx)
    {
        if(!res.count(idx))
        {
            if(idx==s.size())
            {
                res[idx]={""};
                return;
            }
            res[idx]={};
            for(int i=idx+1;i<=s.size();++i)
            {
                string word=s.substr(idx,i-idx);
                if(word_set.count(word))
                {
                    backtrack(s,i);
                    for(const string& succ:res[i])
                    {
                        res[idx].push_back(succ.empty()?word:word+" "+succ);
                    }
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        word_set=unordered_set(wordDict.begin(),wordDict.end());
        backtrack(s,0);
        return res[0];
    }
};


//i do not do it myself
