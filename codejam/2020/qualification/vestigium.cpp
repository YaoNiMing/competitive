#include <iostream>
#include <vector>
#include <map>


int main() {
    int T, N;

    std::cin >> T;
    for (int ti=1; ti<=T; ++ti) {
        std::cin >> N;
        std::vector<std::vector<int>> M(N, std::vector<int>(N, 0));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) { std::cin >> M[i][j]; }
        }
        int trace = 0, column_count = 0, row_count = 0;
        for (int i=0; i<N; ++i) {
            trace += M[i][i];
            std::map<int, int> cm, rm;
            for (int j=0; j<N; ++j) {
                ++rm[M[i][j]];
                if (rm[M[i][j]] > 1) { ++row_count; break; }
            }
            for (int j=0; j<N; ++j) {
                ++cm[M[j][i]];
                if (cm[M[j][i]] > 1) { ++column_count; break; }
            }
        }
        std::cout << "Case #" << ti << ": " << trace << " " << row_count << " " << column_count << std::endl;
    }

}
