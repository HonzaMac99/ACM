#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> Vec1D;
typedef std::vector<std::vector<int>> Vec2D;


int get_score(Vec2D table, Vec2D score, int x, int y, int chr) {
  int n_rows = score.size();
  int n_cols = score[0].size();
  for (int dy = -1; dy <= 1; ++dy) {
    for (int dx = -1; dx <= 1; ++dx) {
      int ny = y + dy;
      int nx = x + dx;
      if ((ny >= 0 and ny < n_rows) and 
          (nx >= 0 and nx < n_cols) and table[ny][nx] == (chr-1)) {
        if (score[ny][nx] == (chr - 'A')) 
          return score[ny][nx] + 1;
      }
    }
  }
  return 0;
}


int main() {
  int count = 1;
    
  while (true) {
    int n_rows, n_cols;
    std::cin >> n_rows >> n_cols;
    if (n_rows == 0 && n_cols == 0)
      break;

    Vec2D table(n_rows, Vec1D(n_cols));
    Vec2D score(n_rows, Vec1D(n_cols, 0));

    bool A_present = false;
    for (int y = 0; y < n_rows; y++) {
      std::string row;
      std::cin >> row;
      for (int x = 0; x < n_cols; x++) {
        table[y][x] = row[x];
        if (table[y][x] == 'A') {
          score[y][x] = 1;
          A_present = true;
        }
      }
    }

    if (not A_present) {
      std::cout << "Case " << count++ << ": " << 0 << std::endl;
      continue;
    }

    for (int chr = 'B'; chr <= 'Z'; chr++) {
      for (int y = 0; y < n_rows; y++) {
        for (int x = 0; x < n_cols; x++) {
          if (table[y][x] == chr) {
            score[y][x] = get_score(table, score, x, y, chr);
          }
        }
      }
    }

    int res = 0;
    for (const auto& row : score) {
      res = std::max(res, *std::max_element(row.begin(), row.end()));
    }

    std::cout << "Case " << count++ << ": " << res << std::endl;
  }

  return 0;
}
