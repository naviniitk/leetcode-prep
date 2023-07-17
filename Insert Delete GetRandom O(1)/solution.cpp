class RandomizedSet {
public:
    RandomizedSet() {
        
    }

    vector<int> values;
    unordered_map<int, int> umap;
    
    bool insert(int val) {
        if(umap.count(val)) return false;
        values.push_back(val);
        umap[val] = values.size() - 1; // To remember the index value so that it can be removed in O(1)
        return true;
    }
    
    bool remove(int val) {
        if(umap.count(val)) {
            int index = umap[val]; // get the index of the val
            int v = values.back(); // we need to swap last element to the index so that we can remove from the last by pop_back()
            values[index] = v; // swapping (don't need to do the other way as the element is going to be deleted)
            umap[v] = index; // update the index of the swapped element
            values.pop_back();
            umap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return values[(rand() % values.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
