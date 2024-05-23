#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int count = 1;
    
    while (true) {
        int n_rows, n_cols;
        std::cin >> n_rows >> n_cols;
        if (n_rows == 0 && n_cols == 0) {
            break;
        }

        std::vector<std::vector<int>> table(n_rows, std::vector<int>(n_cols));
        std::vector<std::vector<int>> score(n_rows, std::vector<int>(n_cols, 0));

        for (int i = 0; i < n_rows; ++i) {
            std::string row;
            std::cin >> row;
            for (int j = 0; j < n_cols; ++j) {
                table[i][j] = row[j];
                if (table[i][j] == 'A') 
                  score[i][j] = 1;
            }
        }

        for (int chr = 'B'; chr <= 'Z'; ++chr) {
            for (int y = 0; y < n_rows; ++y) {
                for (int x = 0; x < n_cols; ++x) {
                    if (table[y][x] == chr) {
                        int max_score = 0;
                        for (int dy = -1; dy <= 1; ++dy) {
                            for (int dx = -1; dx <= 1; ++dx) {
                                int ny = y + dy;
                                int nx = x + dx;
                                if (ny >= 0 && ny < n_rows && nx >= 0 && nx < n_cols && table[ny][nx] == chr - 1) {
                                    max_score = std::max(max_score, score[ny][nx]);
                                }
                            }
                        }
                        score[y][x] += max_score;
                    }
                }
            }
        }

        int res = 0;
        for (const auto& row : score) {
            res = std::max(res, *std::max_element(row.begin(), row.end()));
        }

        std::cout << "Case " << count << ": " << res << std::endl;
        ++count;
    }

    return 0;
}
