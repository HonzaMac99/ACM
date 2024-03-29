#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <tuple>



int main() {


  // std::priority_queue<tuple<int, int, int>> q;
  std::priority_queue<int> q;

  int arr[] = {10, 4, 20, 400, 1, 4, 20};

  for (int i = 0; i < (int)sizeof(arr); i++) {

  }

  for (int i = 0; i < (int)q.size(); i++) {
    int q_el = q.top();
    q.pop();
    std::cout << q_el << std::endl;
  }

  return 0;
}

