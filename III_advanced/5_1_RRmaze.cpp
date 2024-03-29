#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

#define PRINT 0

typedef std::tuple<int, int, int> t3int;
typedef std::priority_queue<t3int, std::vector<t3int>, std::greater<t3int>> min_prior_q;


std::vector<int> get_config_arr(std::string input) {
  int n_dirs = 4;
  std::vector<int> config_arr(n_dirs, 0);
  for (int i = 0; i < (int)input.length(); i++) {
    switch (input[i]) {
      case 'N':
        config_arr[0] = 1;
        break;
      case 'E':
        config_arr[1] = 1;
        break;
      case 'S':
        config_arr[2] = 1;
        break;
      case 'W':
        config_arr[3] = 1;
        break;
      default:
        std::cout << "incorect char: " << input[i] << std::endl;
        break;
    }
  }
  return config_arr;
}


int main() {

  int n_dirs = 4;
  int rows, cols;
  std::string config_str;
  
  while(std::cin >> rows) { 
    std::cin >> cols; 

    std::vector<int> maze[rows][cols];
    bool visited[rows][cols][n_dirs];

    // for (int i = 0; i < rows; i++)
    //   for (int j = 0; j < cols; j++)
    //     for (int k = 0; k < n_dirs; k++)
    //       visited[i][j][k] = false;
    std::memset(visited, 0, sizeof(visited));  // set all bytes to 0

    int i = 0;
    while (i < rows*cols - 1) {
      int row = i % cols; 
      int col = i - row*cols;
      std::cin >> config_str;
      // std::cout << "Line " << i << ": " << config_str << std::endl;
      maze[row][col] = get_config_arr(config_str); 
      i++;
    }

    bool goal_found = false;
    int rot = 0;


    min_prior_q q;
    int path_len = 0;
    t3int start = {path_len, 0, 0};
    int pos_val, pos_x, pos_y;
    q.push(start);

    while (!q.empty() and !goal_found) {
      std::tie(pos_val, pos_x, pos_y) = q.top();
      rot = pos_val % n_dirs;
      q.pop();

      // go through all possible directions
      std::vector<int> config_arr = maze[pos_y][pos_x];
      for (int i = 0; i < n_dirs; i++) {
        int idx = (n_dirs - rot + i) % n_dirs;
        if (config_arr[idx] == 1) {
          int new_pos_x = 0, new_pos_y = 0;
          // going north
          if ((i == 0) and (pos_y - 1 >= 0)) {
            new_pos_x = pos_x;
            new_pos_y = pos_y - 1;
          }
          // going east
          else if ((i == 1) and (pos_x + 1 < cols)) {
            new_pos_x = pos_x + 1;
            new_pos_y = pos_y;
          }
          // going south
          else if ((i == 2) and (pos_y + 1 < rows)) {
            new_pos_x = pos_x;
            new_pos_y = pos_y + 1;
          }
          // going west
          else if ((i == 3) and (pos_x - 1 >= 0)) {
            new_pos_x = pos_x - 1;
            new_pos_y = pos_y;
          }
          // undefined
          else {
            continue;
          }

          if (new_pos_y == rows-1 and new_pos_x == cols-1) 
            goal_found = true;
          else if (!visited[new_pos_y][new_pos_x][(rot+1)%n_dirs]) {
            visited[new_pos_y][new_pos_x][(rot+1)%n_dirs] = true;

            t3int new_pos = {pos_val+1, new_pos_x, new_pos_y};
            q.push(new_pos);
          }
        }
      }
    }
    if (goal_found)
      std::cout << pos_val+1 << std::endl;
    else 
      std::cout << "no path to exit" << std::endl;
  }
  return 0;
}
