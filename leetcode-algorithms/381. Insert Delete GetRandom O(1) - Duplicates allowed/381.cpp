//not real O(1)
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        unmap[val].insert(vec.size());
        vec.push_back(val);
        return unmap[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (unmap.find(val) == unmap.end())
            return 0;
        
        auto it = unmap[val].rbegin();
        if (*it != vec.size() - 1)
        {
            unmap[vec.back()].erase(vec.size() - 1);
            unmap[vec.back()].insert(*it);
            std::swap(vec[*it], vec.back());
        }
        unmap[val].erase(*it);
        vec.pop_back();
        if (unmap[val].empty())
            unmap.erase(val);
        return 1;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
private:
    vector<int> vec;
    unordered_map<int, set<int>> unmap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
