#include <iostream>
#include <vector>
#include <string>


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

// void reverse(std::vector<char> &arr)

int check_idx(int check_status, int same_idx, int diff_idx) {
    // same_idx will check for 'x__x' vs '_xx_'
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
            case 9:  // b'1001'
            case 6:  // b'0110'
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
    std::cerr << "STARTING!" << std::endl;
    int T, B;
    std::cin >> T >> B;
    for (int ti = 0; ti < T; ++ti) {
        // pair of char (idx, B-1-idx) with same value and different values
        curser cur(B);
        int same_idx = -1, diff_idx = -1;
        std::vector<char> arr(B, 'x');
        int check_status;
        for (int q=0; q<MAX_Q; ++q) {
            if (need_check) {

            }
            else {
                int idx = cur.next();
                std::cerr << idx + 1 << std::endl;
                std::cout << idx + 1 << std::endl;
                char c;
                std::cin >> c;
                std::cerr << c << std::endl;
                arr[idx] = c;
            }
            if
        }
    }
}
