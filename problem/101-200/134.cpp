//search
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int hasGas = 0;
        int n = gas.size();
        for(int i=0;i<n;++i)
        {
            if(gas[i]>=cost[i])
            {
                int sumGas = 0;
                int cnt=i;
                while(sumGas>=0)
                {
                    sumGas+=gas[cnt]-cost[cnt];
                    cnt++;
                    if(cnt==n)
                    {
                        cnt=0;
                    }
                    if(cnt==i&&sumGas>=0)
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};

//leetcode solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
