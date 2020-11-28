#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


# define MAX_Q 150

struct curser {
    int idx, size;
    bool on_left, pair_queried;

private:
    void move() {
        if (pair_queried) {
            ++idx;
            pair_queried = false;
            on_left = true;
        }
        else {
            pair_queried = true;
            on_left = !on_left;
        }
    }
public:
    int next() {
        move();
        return on_left ? idx : (size - 1 - idx);
    }
    curser(int size) : size(size) {
        idx = -1;
        on_left = true;
        pair_queried = true;
    }
};

void reverse(std::vector<char> &arr, curser &cur) {
    std::reverse(arr.begin(), arr.end());
    cur.on_left = !cur.on_left;
}

void negate(std::vector<char> &arr) {
    for (char &c : arr) {
        c = '0' + ((c - '0') ^ 1);
    }
}

int check_idx(int check_status, int same_idx, int diff_idx) {
    // same_idx will check for '_x_x' vs 'x_x_'
    // diff_idx will check for '__xx' vs 'xx__'
    switch(check_status) {
        case 8: // b'1000'
        case 4: // b'0100'
        case 2: // b'0010'
        case 1: // b'0001'
            return -1;
    }
    if (same_idx >= 0) {
        switch(check_status) {
            case 5:  // b'0101'
            case 10:  // b'1010'
                break;
            default:
                return same_idx;
        }
    }
    if (diff_idx >= 0) {
        switch(check_status) {
            case 3:  // b'0011'
            case 12: // b'1100'
                break;
            default:
                return diff_idx;
        }
    }
    return -1;
}

int main() {
    int T, B;
    std::cin >> T >> B;
    for (int ti = 0; ti < T; ++ti) {
        // pair of char (idx, B-1-idx) with same value and different values
        curser cur(B);
        int same_idx = -1, diff_idx = -1;
        std::vector<char> arr(B, 'x');
        int check_status = 1;
        int count = 0;
        for (int q=0; q<MAX_Q; ++q) {
            int idx = check_idx(check_status, same_idx, diff_idx);
            if (idx >= 0) {
                std::cout << idx + 1 << std::endl;
                char c;
                std::cin >> c;
                if (arr[idx] == c) {
                    if (idx == same_idx) { check_status &= 5; } // 0101
                    else { check_status &= 3; } // 0011
                }
                else {
                    if (idx == same_idx) { check_status &= 10; } // 1010
                    else { check_status &= 12; } // 1100
                }
                if (check_idx(check_status, same_idx, diff_idx) < 0) {
                    switch(check_status) {
                        case 8: negate(arr); break;
                        case 4: reverse(arr, cur); break;
                        case 2: reverse(arr, cur); negate(arr); break;
                        case 1: break;
                        case 5: check_status = 1; break;
                        case 10: negate(arr); check_status = 1; break;
                        case 3: check_status = 1; break;
                        case 12: reverse(arr, cur); check_status = 1; break;
                    }
                }
            }
            else {
                int prev_cur_idx = cur.idx;
                int q_idx = cur.next();
                std::cout << q_idx + 1 << std::endl;
                char c;
                std::cin >> c;
                if (arr[q_idx] != '0' && arr[q_idx] != '1') { ++count; }
                arr[q_idx] = c;

                if (count >= B) {
                    for (int i = 0; i < B; ++i) { std::cerr << arr[i]; }
                    std::cerr << std::endl;
                    for (int i = 0; i < B; ++i) { std::cout << arr[i]; }
                    std::cout << std::endl;
                    std::cin >> c;
                    if (c != 'Y') { return 1; }
                    break;
                }
                if (prev_cur_idx == cur.idx) {
                    if (same_idx < 0 && arr[cur.idx] == arr[B - 1 - cur.idx]) {
                        same_idx = cur.idx;
                    }
                    if (diff_idx < 0 && arr[cur.idx] != arr[B - 1 - cur.idx]) {
                        diff_idx = cur.idx;
                    }
                }
            }
            if (q % 10 == 9) { check_status = 15; cur.pair_queried=false; }
        }
    }
}
