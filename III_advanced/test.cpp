#include <iostream>
#include <sstream>
#include <fstream>

#define PRINT 0

int* get_f_ints(std::string file_line, int len) {
  std::stringstream ss;
  int *number_array = new int[len]; 

  ss << file_line;

  // Check all words in the line for any ints 
  int i = 0;
  while(!ss.eof()) {
    ss >> number_array[i];
    i++;
  }
  return number_array;
}


int* get_cin_ints(int len) {
  int *number_array = new int[len]; 

  for(int i = 0; i < len; i++) 
    std::cin >> number_array[i];
  return number_array;
}


int get_odd_sum(int a, int b) {
  int odd_sum = 0;
  int cur_num = (a % 2 == 0) ? a+1 : a;

  while(cur_num <= b) {
    odd_sum += cur_num;
    cur_num += 2;
  }

  return odd_sum;
}


int main(int argc, char* argv[]) {

  // Read the input from file or stdin
  std::string file_name;
  int stdin_input = 1;
  if (argc > 1) {
    file_name = argv[1];
    if (file_name == "-f")
      file_name = "/home/honzamac/cvut/m2/ACM/III_advanced/files/1_04_odd_sum.in";
    stdin_input = 0;
  }

  if (stdin_input) {
    int n_cases; 
    int num_1, num_2, result = 0;
    
    std::cin >> n_cases; 

    int i = 0;
    while (i < n_cases) {
      std::cin >> num_1;
      std::cin >> num_2;

      result = get_odd_sum(num_1, num_2);
      std::cout << "Case " << i+1 << ": " << result << std::endl;

      i++;
    }
  }
  else {

    std::ifstream MyReadFile(file_name);
    std::string fileLine;

    getline(MyReadFile, fileLine);
    int n_cases = get_f_ints(fileLine, 1)[0]; 

    int num_1, num_2, result = 0;

    int i = 0;
    while (i < n_cases) {
      getline(MyReadFile, fileLine);
      num_1 = get_f_ints(fileLine, 1)[0];

      getline(MyReadFile, fileLine);
      num_2 = get_f_ints(fileLine, 1)[0];

      result = get_odd_sum(num_1, num_2);
      std::cout << "Case " << i+1 << ": " << result << std::endl;

      i++;
    }
    MyReadFile.close();
  }

  return 0;
}
