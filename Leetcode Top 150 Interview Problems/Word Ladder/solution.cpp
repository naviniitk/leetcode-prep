class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string x : wordList) {
            st.insert(x);
        }

        queue<string> q;
        q.push(beginWord);
        set<string> visited;

        int ans = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return ans;
                
                for(int j = 0; j < word.size(); j++) {
                    for(int k = 'a'; k <= 'z'; k++) {
                        string temp = word;
                        temp[j] = (char)k;
                        if(st.find(temp) != st.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};

// Better solution

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
