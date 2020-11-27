#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <sstream>


int main() {
    int T;
    std::cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        // logics here
        std::stringstream ss;
        bool is_possible = true;
        int N, c_available = 0, j_available = 0;
        std::cin >> N;
        std::vector<std::tuple<int, int, int>> activities;
        activities.reserve(N);
        std::string res(N, 0);

        for (int i=0; i<N; ++i) {
            int s, e;
            std::cin >> s >> e;
            activities.emplace_back(std::tuple<int, int, int>(s, e, i));
        }
        std::sort(
            activities.begin(), activities.end(),
            [](const auto &a, const auto &b) { return std::get<0>(a) < std::get<0>(b); }
        );

        for (const auto[s, e, idx] : activities) {
            if (s >= c_available) {
                res[idx] = 'C';
                c_available = e;
            }
            else if (s >= j_available) {
                res[idx] = 'J';
                j_available = e;
            }
            else { is_possible = false; break; }
        }
        std::cout << "Case #" << ti << ": ";
        std::cout << (is_possible ? res : "IMPOSSIBLE");
        std::cout << std::endl;
    }
}
