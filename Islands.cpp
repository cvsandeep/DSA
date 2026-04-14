#include <cstdio>
#include <vector>

static constexpr int kDx[] = {-1, 1, 0, 0};
static constexpr int kDy[] = {0, 0, -1, 1};

static void dfs(std::vector<std::vector<int>>& g, int R, int C, int x, int y) {
  if (x < 0 || x >= R || y < 0 || y >= C || g[x][y] == 0) return;
  g[x][y] = 0;
  for (int i = 0; i < 4; i++) dfs(g, R, C, x + kDx[i], y + kDy[i]);
}

int numIslands(std::vector<std::vector<int>>& grid) {
  int R = (int)grid.size();
  if (!R) return 0;
  int C = (int)grid[0].size();
  if (!C) return 0;
  int n = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (grid[i][j] == 1) {
        n++;
        dfs(grid, R, C, i, j);
      }
  return n;
}

#if 0
int main() {
  std::vector<std::vector<int>> grid = {
      {1, 1, 0, 0, 0},
      {1, 1, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 1, 1},
  };
  std::printf("%d\n", numIslands(grid));
  return 0;
}
#endif
