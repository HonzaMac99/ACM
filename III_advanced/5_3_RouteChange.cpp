#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

#define PRINT 0

typedef std::tuple<int, int> t2int;
typedef std::tuple<int, int, int> t3int;
// puts minimal value on the top
typedef std::priority_queue<t2int, std::vector<t2int>, std::greater<t2int>> min_prior_q;
// typedef std::priority_queue<t3int, std::vector<t3int>, std::greater<t3int>> min_prior_q;


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

  int n_cities, n_roads, c_len, city_k;

  while(std::cin >> n_cities >> n_roads >> c_len >> city_k) { 
    if ((n_cities + n_roads + c_len + city_k) == 0) 
      break;
    
    int** adj_mat = new int*[n_cities];
    for (int i = 0; i < n_cities; i++) {
      adj_mat[i] = new int[n_cities];
      for (int j = 0; j < n_cities; j++) 
        adj_mat[i][j] = -1;
    }

    // store the edge values
    int city_in, city_out, road_cost; 
    for (int i = 0; i < n_roads; i++) {
      std::cin >> city_in >> city_out >> road_cost;
      adj_mat[city_in][city_out] = road_cost;
      adj_mat[city_out][city_in] = road_cost;
    } 
    // print_mat(adj_mat, n_cities);

    // define the cost to destination on the service road c
    int c_cities_cost[c_len];
    int cost_to_dest = 0;
    for (int i = c_len-1; i > 0; i--) {
      c_cities_cost[i] = cost_to_dest;
      cost_to_dest += adj_mat[i][i-1];
    } 
    c_cities_cost[0] = cost_to_dest;


    int city_cost, city_id;
    bool visited[n_cities];
    std::memset(visited, 0, sizeof(visited));  // set all bytes to 0

    
    t2int start = {0, city_k};
    min_prior_q q;
    visited[city_k] = true;
    // std::cout << "Start: " << city_k << " " << 0 << std::endl; 
    q.push(start);

    int min_path_cost = n_roads*250;
    while(!q.empty()) {
      std::tie(city_cost, city_id) = q.top();
      q.pop();
      visited[city_id] = true;

      for (int i = 0; i < n_cities; i++) {
        int e_cost = adj_mat[city_id][i];
        if (e_cost == -1) 
          continue;

        if (i < c_len) {
          int path_cost = city_cost + e_cost + c_cities_cost[i];
          if (path_cost < min_path_cost) {
            min_path_cost = path_cost;
            // std::cout << "Best path: " << min_path_cost << std::endl; 
          }
        }
        // std::cout << visited[i]  << " " << e_cost << std::endl;
        else if (not visited[i]) {
          // visited[i] = true;
          int next_city_cost = e_cost + city_cost;
          t2int next_city = {next_city_cost, i};
          // std::cout << "Pushing: " << next_city_cost << " " << i << std::endl; 
          q.push(next_city);
        }
      }
    }
    std::cout << min_path_cost << std::endl;

    // deallocate
    for (int i = 0; i < n_cities; i++) 
      delete[] adj_mat[i];
    delete[] adj_mat;
  }
  return 0;
}
