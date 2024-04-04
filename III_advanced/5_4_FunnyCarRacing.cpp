#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

#define PRINT 0

typedef std::vector<int> v_int;
typedef std::tuple<int, int> t2int;
typedef std::tuple<int, int, int> t3int;
// puts minimal value on the top
typedef std::priority_queue<t2int, std::vector<t2int>, std::greater<t2int>> min_prior_q;
// typedef std::priority_queue<t3int, std::vector<t3int>, std::greater<t3int>> min_prior_q;
// typedef std::priority_queue<v_int, std::vector<v_int>, std::greater<v_int>> min_prior_q;

bool in_vec(std::vector<int> vec, int var) {
  return (std::find(vec.begin(), vec.end(), var) != vec.end());
}


void print_mat(int** mat, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) 
      std::cout << mat[i][j] << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
} 


int main() {

  int n_js, n_roads, start_id, end_id;

  int case_id = 1;
  while(std::cin >> n_js >> n_roads >> start_id >> end_id) { 
    

    // store the edge values
    std::vector<std::vector<std::vector<int>>> adj_list(n_js);
    // for (int i = 0; i < n_js; i++) {
    //   std::vector<std::vector<int>> js_out = {};
    //   adj_list.push_back(js_out);
    // }

    int js_in_id, js_out_id, t_open, t_closed, t_drive; 
    for (int i = 0; i < n_roads; i++) {
      std::cin >> js_in_id >> js_out_id >> t_open >> t_closed >> t_drive;
      std::vector<int> js_out =  {js_out_id, t_open, t_closed, t_drive};
      adj_list[js_in_id].push_back(js_out);
    } 

    int min_path_cost = -1;

    min_prior_q q;
    t2int start = {0, start_id};
    q.push(start);

    int js_id, js_cost;
    while(!q.empty()) {
      std::tie(js_id, js_cost) = q.top();
      int n_js_out = adj_list[js_id].size();
      for (int i = 0; i < n_js_out; i++) {

      }
    }

    std::cout << "Case " << case_id << ": " << min_path_cost << std::endl;
    case_id++;
  }
  return 0;
}
