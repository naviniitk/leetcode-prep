class Solution
{
public:
  bool wordPattern(string pattern, string s)
  {
    unordered_map<char, string> match;
    unordered_map<string, bool> used;
    vector<string> words;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == ' ')
      {
        words.push_back(temp);
        temp = "";
      }
      else
        temp += s[i];
    }
    words.push_back(temp);
    if (words.size() != pattern.size())
      return false;

    int wordCount = 0;
    for (int i = 0; i < words.size(); i++)
    {
      if (match.count(pattern[i]))
      {
        if (match[pattern[i]] != words[i])
          return false;
      }
      else
      {
        if (used[words[i]])
          return false;
        match[pattern[i]] = words[i];
        used[words[i]] = true;
      }
    }
    return true;
  }
};
