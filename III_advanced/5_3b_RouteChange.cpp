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


    int city_cost, city_id;
    bool visited[n_cities];
    std::memset(visited, 0, sizeof(visited));  // set all bytes to 0
    min_prior_q q;

    // define the cost to destination on the service road c
    int c_cities_cost[c_len];
    int cost_to_dest = 0;
    for (int i = c_len-1; i > 0; i--) {
      c_cities_cost[i] = cost_to_dest;
      t2int c_city = {cost_to_dest, i};
      q.push(c_city);
      cost_to_dest += adj_mat[i][i-1];
    } 
    c_cities_cost[0] = cost_to_dest;
    t2int c_city = {cost_to_dest, 0};
    q.push(c_city);

    int min_path_cost = 0;
    bool k_reached = false;
    while(!q.empty() and !k_reached) {
      std::tie(city_cost, city_id) = q.top();
      q.pop();
      visited[city_id] = true;

      for (int i = c_len; i < n_cities; i++) {
        int e_cost = adj_mat[city_id][i];
        if (e_cost == -1) 
          continue;

        if (i == city_k) {
          k_reached = true;
          min_path_cost = city_cost + e_cost;
        }
        else if (not visited[i]) {
          // visited[i] = true;
          int next_city_cost = city_cost + e_cost;
          t2int next_city = {next_city_cost, i};
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
