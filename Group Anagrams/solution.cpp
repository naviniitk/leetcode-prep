// O(n * mlogm) time ans O(n) space, m is length of word
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(auto x:strs) {
            string word = x;
            sort(word.begin(), word.end());
            umap[word].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:umap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

// O(n * m) time

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector<string>> v;
        map<vector<int>,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++)
        {   
            vector<int> count(26,0);
            for(int j=0;j<strs[i].length();j++)
            {
                count[strs[i][j] - 'a']+=1;
            }
            mp[count].push_back(strs[i]); // whole array as a key, good. thats what I was thinking
        }

        for(auto it: mp)
        {
            v.push_back(it.second);
        }

        return v;
    }
};
