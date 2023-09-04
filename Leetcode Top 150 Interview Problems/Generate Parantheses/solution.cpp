class Solution
{
public:
  void parenthesis(int open, int close, vector<string> &ans, string currValid)
  {
    if (open == 0 && close == 0)
    {
      ans.push_back(currValid);
      return;
    }
    if (open > 0)
      parenthesis(open - 1, close, ans, currValid + "(");
    if (close > 0 && close > open)
      parenthesis(open, close - 1, ans, currValid + ")");
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    parenthesis(n, n, ans, "");
    return ans;
  }
};
