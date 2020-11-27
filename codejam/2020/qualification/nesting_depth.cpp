#include <iostream>
#include <string>
#include <sstream>

int main() {
    int T;
    std::cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        std::string s;
        std::cin >> s;
        std::stringstream ss;
        int prev = 0;
        for (char c : s) {
            int curr = int(c) - 48;
            for (int i=0; i<curr - prev; ++i) {ss << '(';}
            for (int i=0; i<prev - curr; ++i) {ss << ')';}
            ss << c;
            prev = curr;
        }
        for (int i=0; i<prev; ++i) { ss << ')'; }
        std::string res;
        ss >> res;
        std::cout << "Case #" << ti << ":" << res <<std::endl;
    }

}
