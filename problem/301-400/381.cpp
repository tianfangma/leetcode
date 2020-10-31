//idx存储数字在nums中的位置
//nums存储重复的数字，在删除时，只需要将删除元素和最后一个元素交换位置删除即可

class RandomizedCollection {
public:
private :
    unordered_map<int,unordered_set<int>>idx;
    vector<int>nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.emplace_back(val);
        idx[val].insert(nums.size()-1);
        return idx[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(idx.find(val)==idx.end())
        {
            return false;
        }
        int i = *(idx[val].begin());//val元素在nums中的位置
        nums[i]=nums[nums.size()-1];//交换元素
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size()-1);
        if(i<nums.size()-1)//如果i不是最后一个元素，将新位置添加进集合
        {
            idx[nums[i]].insert(i);
        }
        if(idx[val].size()==0)//如果val被全部删除
        {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[random()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
