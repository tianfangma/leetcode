/first edition
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()==0)
        {
            return false;
        }
        int state=0;//当前状态，0初始，1上升，2下降
        int prev=A[0];
        for(int i=1;i<A.size();++i)
        {
            if(prev==A[i])//相等一定是错的
            {
                state=0;
                break;
            }
            if(prev<A[i])//上升状态
            {
                if(state==0)
                {
                    state=1;
                }
                if(state!=1)
                {
                    state=0;
                    break;
                }
            }
            if(prev>A[i])
            {
                if(state==1)
                {
                    state=2;
                }
                if(state!=2)
                {
                    break;
                }
            }
            prev=A[i];
        }
        return state==2;
    }
};

//linear scan
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i=0;
        int N=A.size();
        while(i+1<N&&A[i]<A[i+1])
        {
            ++i;
        }
        if(i==0||i==N-1)
        {
            return false;
        }
        while(i+1<N&&A[i]>A[i+1])
        {
            ++i;
        }
        return i==N-1;
    }
};

//most defeat
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len=A.size()-1;
        int left=0,right=len;
        while(left+1<=right&&A[left]<A[left+1])
        {
            left++;
        }
        while(right>0&&A[right]<A[right-1])
        {
            right--;
        }
        return left>0&&right<len&&left==right;
    }
};
