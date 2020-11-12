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

//double traverse
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n=A.size();
        vector<int> res(n);
        int i=0;
        for(int x : A)
        {
            if(x%2==0)
            {
                res[i]=x;
                i+=2;
            }
        }
        i=1;
        for(int x : A)
        {
            if(x%2!=0)
            {
                res[i]=x;
                i+=2;
            }
        }
        return res;
    }
};

//two pointer
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n=A.size();
        int j=1;
        for(int i=0;i<n;i+=2)
        {
            if(A[i]%2!=0)
            {
                while(A[j]%2==1)
                {
                    j+=2;
                }
                swap(A[i],A[j]);
            }
        }
        return A;
    }
};
