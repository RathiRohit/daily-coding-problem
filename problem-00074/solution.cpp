class RandomizedSet {
    private:
        vector<int> vals;
        unordered_map<int, int> posMap;
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
            srand(time(NULL));
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (posMap.find(val) != posMap.end()) {
                return false;
            }
            
            vals.push_back(val);
            posMap[val] = vals.size() - 1;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (posMap.find(val) == posMap.end()) {
                return false;
            }
            
            posMap[vals[vals.size() - 1]] = posMap[val];
            swap(vals[posMap[val]], vals[vals.size() - 1]);
            vals.pop_back();
            posMap.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            return vals[rand() % vals.size()];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
