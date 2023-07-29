// O(n) time and O(1) space
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap; // max length 26 only lower chars
        for(auto m:magazine) {
            umap[m]++;
        }
        for(auto r:ransomNote) {
            if(umap.find(r) == umap.end() || umap[r] == 0)
                return false;
            else umap[r]--;
        }
        return true;
    }
};
