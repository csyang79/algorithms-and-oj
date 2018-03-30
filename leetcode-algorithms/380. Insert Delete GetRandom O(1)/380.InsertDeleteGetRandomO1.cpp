class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (unmap.find(val) != unmap.end())
            return 0;
        unmap.insert(make_pair(val, vec.size()));
        vec.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if (unmap.find(val) == unmap.end())
            return 0;
        int t = unmap[val];
        if (t != vec.size() - 1)
        {
            unmap[vec.back()] = t;
            std::swap(vec[t], vec.back());
        }
        unmap.erase(val);
        vec.pop_back();
        return 1;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
private:
    vector<int> vec;
    unordered_map<int, int> unmap;
};
