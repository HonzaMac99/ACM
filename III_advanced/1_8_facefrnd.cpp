#include<bits/stdc++.h>

// counting the number of friends of friens of Bob
int main() {
    int n_friends, f_id, n_fof;
    std::cin >> n_friends;
    std::set<int> unique_ids;

    for (int i = 0; i < n_friends; i++) {
      // keep friend id, number of friends of this friend
      std::cin >> f_id >> n_fof; 
      unique_ids.insert(f_id);

      // Set will automatically keep the unique so no duplicate
      for(int i = 0; i < n_fof; i++) {
        std::cin >> f_id;
        unique_ids.insert(f_id);
      }
    }

    // Print friend of friends by subtracting his direct friends
    std::cout << unique_ids.size() - n_friends << std::endl;
}
