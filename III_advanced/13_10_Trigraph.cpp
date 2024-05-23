#include <iostream
#include <vector>
#include <algorithm>
#include <limits>

typedef std::vector<std::vector<int>> Vec2D;

int main() {
    int count = 1;

    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) 
            break;
        

        Vec2D score(n, std::vector<int>(3));

        for (int i = 0; i < n; ++i) {
            std::cin >> score[i][0] >> score[i][1] >> score[i][2];
        }

        score[0][0] = std::numeric_limits<int>::max();
        score[0][2] += score[0][1];

        for (int i = 1; i < n; ++i) {
            score[i][0] += std::min(score[i-1][0], score[i-1][1]);
            score[i][1] += std::min({score[i-1][0], score[i-1][1], score[i-1][2], score[i][0]});
            score[i][2] += std::min({score[i-1][1], score[i-1][2], score[i][1]});
        }

        std::cout << count << ". " << score[n-1][1] << std::endl;
        count++;
    }

    return 0;
}
