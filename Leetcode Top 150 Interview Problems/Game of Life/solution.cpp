class Solution
{
public:
  vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  void gameOfLife(vector<vector<int>> &board)
  {
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        int childlivecount = 0;
        for (auto &mvt : movements)
        {
          int ni = i + mvt.first;
          int nj = j + mvt.second;
          if (ni < 0 || nj < 0 || ni >= r || nj >= c)
            continue;
          if (board[ni][nj] >= 1 && board[ni][nj] <= 4)
            childlivecount++;
        }
        if (board[i][j] == 0)
        {
          if (childlivecount == 3)
          {
            board[i][j] = 5; // mapped as live count 3 and current cell zero (reproduction)
          }
        }
        else if (childlivecount < 2)
          board[i][j] = 2; // 2 mapped as live count 1
        else if (childlivecount == 2 || childlivecount == 3)
          board[i][j] = 3; // mapped as live count 2, 3
        else if (childlivecount > 3)
          board[i][j] = 4; // all others
      }
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (board[i][j] == 2)
          board[i][j] = 0;
        else if (board[i][j] == 3)
          board[i][j] = 1;
        else if (board[i][j] == 4)
          board[i][j] = 0;
        else if (board[i][j] == 5)
          board[i][j] = 1;
      }
    }
  }
};
