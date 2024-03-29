#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <tuple>


int main() {
  
  typedef std::tuple<int, int, int> t3int;
  // std::priority_queue<t3int> max_q;
  
  // sorts the elements that the min value is on top
  std::priority_queue<t3int, std::vector<t3int>, std::greater<t3int>> q;

  int arr[] = {10, 4, 20, 400, 1, 4, 20};
  int arr_len = sizeof(arr) / sizeof(int);
  std::cout << "Array size is " << arr_len << "\n" << std::endl;

  for (int i = 0; i < arr_len; i++) {
    t3int t = {arr[i], i, arr_len-i};
    std::cout << arr[i] << " " << i << " " << arr_len-i << std::endl;
    q.push(t);
  }

  int q_len = q.size();
  std::cout << "\nQueue size is " << q_len << "\n" << std::endl;

  for (int i = 0; i < q_len; i++) {
    int el_val, el_x, el_y;
    std::tie(el_val, el_x, el_y) = q.top();
    q.pop();
    std::cout << el_val << " " << el_x << " " << el_y << std::endl;
  }

  return 0;
}

