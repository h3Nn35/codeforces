#include <iostream>

int main() {
    int t;
    std::cin >> t;  // number of test cases

    for (int i = 0; i < t; i++) {
        int k;
        std::cin >> k;  // k-th element to find

        int num = 1;
        while (k > 0) {
            if (num % 3 != 0 && num % 10 != 3) {
                k--;
            }
            num++;
        }

        std::cout << num - 1 << std::endl;
    }

    return 0;
}