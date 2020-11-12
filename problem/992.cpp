by tianfangma
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int>res;
        int len=A.size();
        for(int i=0;i<len;++i)
        {
            int temp=i;
            if(i%2==0)//even number
            {
                while(A[temp]%2!=0||A[temp]==-1)
                {
                    temp++;
                }
            }
            else//odd number
            {
                while(A[temp]%2==0||A[temp]==-1)
                {
                    temp++;
                }
            }
            res.emplace_back(A[temp]);
            A[temp]=A[i];
            A[i]=-1;
        }
        return res;
    }
};
