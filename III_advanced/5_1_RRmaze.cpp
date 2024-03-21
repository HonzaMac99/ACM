#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define PRINT 0


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
    // std::cout << "[" << config_arr[0] << ", " 
    //                  << config_arr[1] << ", " 
    //                  << config_arr[2] << ", " 
    //                  << config_arr[3] << "]" << std::endl;
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
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        for (int k = 0; k < n_dirs; k++)
          visited[i][j][k] = false;

    int i = 0;
    while (i < rows*cols - 1) {
      int row = i % cols; 
      int col = i - row*cols;
      std::cin >> config_str;
      // std::cout << "Line " << i << ": " << config_str << std::endl;
      std::vector<int> config_arr = get_config_arr(config_str);
      maze[row][col] = config_arr;
      i++;
    }
    // for (int i = 0; i < rows; i++) {
    //   for (int j = 0; j < cols; j++) {
    //     if (i*j == (rows-1)*(cols-1))
    //       break;
    //     std::vector<int> config_arr = maze[i][j];
    //   }
    // }
    // std::cout << std::endl;

    bool goal_found = false;
    int path_cost = 0;
    int rotation = 0;

    std::vector<std::vector<int>> frontier;
    std::vector<int> start = {0, 0};
    std::vector<int> pos;
    frontier.push_back(start);

    while (!frontier.empty() and !goal_found) {
      std::vector<std::vector<int>> new_frontier;
      while (!frontier.empty()) {
        pos = frontier.back();
        visited[pos[0]][pos[1]][rotation] = true;
        // std::cout << "[" << pos[0] << ", " << pos[1] << "]" << std::endl; 
        frontier.pop_back();

        // go through all possible directions
        std::vector<int> config_arr = maze[pos[0]][pos[1]];
        for (int i = 0; i < n_dirs; i++) {
          int idx = (i - rotation + n_dirs) % n_dirs;
          // std::cout << idx << " = (" << i << " - " << rotation << ") % " << n_dirs << " ---> " << config_arr[idx] << std::endl;
          if (config_arr[idx] == 1) {
            std::vector<int> new_pos(2, 0);
            if ((i == 0) and (pos[0] - 1 >= 0)) {
              // std::cout << "going north" << std::endl;
              new_pos = {pos[0] - 1, pos[1]};
            }
            else if ((i == 1) and (pos[1] + 1 < cols)) {
              // std::cout << "going east" << std::endl;
              new_pos = {pos[0], pos[1] + 1};
            }
            else if ((i == 2) and (pos[0] + 1 < rows)) {
              // std::cout << "going south" << std::endl;
              new_pos = {pos[0] + 1, pos[1]};
            }
            else if ((i == 3) and (pos[1] - 1 >= 0)) {
              // std::cout << "going west" << std::endl;
              new_pos = {pos[0], pos[1] - 1};
            }
            else {
              // std::cout << "no way" << std::endl;
              continue;
            }

            if (new_pos[0] == cols-1 and new_pos[1] == rows-1) 
              goal_found = true;
            else if (!visited[new_pos[0]]
                             [new_pos[1]]
                             [(rotation+1)%n_dirs]) {
              new_frontier.push_back(new_pos);
            }
          }
        }
      }
      path_cost += 1;
      rotation = (rotation + 1) % n_dirs;
      frontier = new_frontier;
      // std::cout << "rotated" << std::endl;
    }

    if (goal_found) {
      std::cout << path_cost << std::endl;
    }
    else {
      std::cout << "no path to exit" << std::endl;
    }
  }
  return 0;
}
